#ifndef VSCodeTerminalManipulator_h
#define VSCodeTerminalManipulator_h

#include "StreamReaders.h"
#include "Terminal.h"

const constexpr size_t VSCODE_DEFAULT_MAX_BUFFER_LENGTH = 127;
const constexpr char CONTROL_ESCAPE_CHAR = 0x1B;
const constexpr char ENTER_CONTROL = 0x0D;
const constexpr char DELETE_CHAR = 0x7F;

const constexpr char CURSOR_CONTROL_SUB_CONTROL = 0x5B;

template <size_t MAX_BUFFER_LENGTH = VSCODE_DEFAULT_MAX_BUFFER_LENGTH>
class VSCodeTerminalManipulator
{
public:
    VSCodeTerminalManipulator(Terminal<VSCodeTerminalManipulator>& terminal)
        : terminal(terminal)
    {}

    void (*enterPressedHandler)(String&);

private:
    friend class Terminal<VSCodeTerminalManipulator>; //For operator()

    void backspacePressed()
    {
        if (terminal.unread.length() != 0)
            terminal.unread.remove(terminal.unread.length() - cursorOffset - 1, 1);

        if (cursorOffset == 0)
        {
            terminal.out.write('\b');
            terminal.out.write(' ');
            terminal.out.write('\b');
            return;
        }

        //Reprint and a space to make sure no trailing char.
        terminal.out.write('\r');
        terminal.out.print(terminal.unread);
        terminal.out.print(' ');
        terminal.out.print('\b');

        moveCursor();
    }

    void moveCursor()
    {
        const constexpr char LEFT = 0x44;
        for (uint8_t i = 0; i < cursorOffset; i++)
        {
            terminal.out.write(CONTROL_ESCAPE_CHAR);
            terminal.out.write(CURSOR_CONTROL_SUB_CONTROL);
            terminal.out.write(LEFT);
        }
    }

    void reprintAtCursorPosition()
    {
        terminal.out.write(terminal.unread[terminal.unread.length() - cursorOffset - 1]);
    }

    void enterPressed()
    {
        if (enterPressedHandler)
            enterPressedHandler(terminal.unread);
        terminal.unread = "";
        cursorOffset = 0;
        terminal.out.print("\r\n");
    }

    void cursorControl()
    {
        using StreamReaders::blockingRead;
        const constexpr char RIGHT = 0x43;
        const constexpr char LEFT = 0x44;

        int move = blockingRead(terminal.in);

        switch (move)
        {
        case LEFT:
            if (cursorOffset != terminal.unread.length())
                cursorOffset++;
            break;
        case RIGHT:
            if (cursorOffset == 0)
                return;
            cursorOffset--;
            reprintAtCursorPosition();
            return;
        default:
            return;
        }

        terminal.out.write(CONTROL_ESCAPE_CHAR);
        terminal.out.write(CURSOR_CONTROL_SUB_CONTROL);
        terminal.out.write(move);
    }

    void controlCharacter()
    {
        using StreamReaders::blockingRead;

        int control = terminal.in.read();

        switch (control)
        {
        case ENTER_CONTROL:
            enterPressed();
            break;
        case CONTROL_ESCAPE_CHAR:
            int subControl = blockingRead(terminal.in);
            switch (subControl)
            {
            case CURSOR_CONTROL_SUB_CONTROL:
                cursorControl();
                break;
            default:
                //Unknown cusor control.
                terminal.out.write(control);
                terminal.out.write(subControl);
                break;
            }
            break;
        default:
            //Unknown control character, route to out.
            terminal.out.write(control);
            break;
        }
    }

    int operator()(const int& peeked) {
        if (peeked < 0)
            return REJECT_NEXT_CHARACTER;

        if (peeked == DELETE_CHAR)
        {
            backspacePressed();
            return DISPOSE_NEXT_CHARACTER;
        }

        if (peeked < ' ')
        {
            controlCharacter();
            return REJECT_NEXT_CHARACTER;
        }

        if (terminal.unread.length() == MAX_BUFFER_LENGTH)
            return DISPOSE_NEXT_CHARACTER;

        return ACCEPT_NEXT_CHARACTER;
    }

private:
    Terminal<VSCodeTerminalManipulator>& terminal;
    uint8_t cursorOffset; //offset to the left
};

#endif
