#ifndef Terminal_h
#define Terminal_h

#include "StreamConstants.h"

const constexpr int REJECT_NEXT_CHARACTER = 0; //Do not read, do not save the next character.
const constexpr int DISPOSE_NEXT_CHARACTER = 1; //Read the next characters, but does not save it (lost char).
const constexpr int ACCEPT_NEXT_CHARACTER = 2; //Read and save the next character.

template <typename TManipulator>
class Terminal : public Stream
{
public:
    Terminal(Stream& in, Print& out)
        : _manipulator(TManipulator(*this)), in(in), out(out), unread(String())
    {}

    void refresh()
    {
        const int& peeked = in.peek();
        switch (_manipulator(peeked))
        {
        case REJECT_NEXT_CHARACTER:
            return;
        default:
        case ACCEPT_NEXT_CHARACTER:
            unread += (char)peeked;
            out.write(peeked);
        case DISPOSE_NEXT_CHARACTER:
            in.read();
        }
    }

    size_t write(uint8_t value)
    {
        out.write(value);
    }

    int availableForWrite()
    {
        return out.availableForWrite();
    }

    int available()
    {
        return unread.length();
    }

    int peek()
    {
        int length;
        if ((length = unread.length()) == 0)
            return EOF;
        return unread[0];
    }

    int read()
    {
        int value = peek();
        if (value >= 0)
            unread.remove(0, 1);
        return value;
    }

    TManipulator& manipulator()
    {
        return _manipulator;
    }

private:
    friend TManipulator;

    TManipulator _manipulator;
    Stream& in;
    Print& out;
    String unread;
};

#endif
