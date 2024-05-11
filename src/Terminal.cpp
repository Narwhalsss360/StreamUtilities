#include "Terminal.h"

const constexpr char DELETE = 0x7F;

Terminal::Terminal(Stream& stream, size_t maxBufferSize, char deleteCharacter, const char* lineEnding)
    : stream(stream), unread(""), maxBufferSize(maxBufferSize), deleteCharacter(deleteCharacter), lineEnding(lineEnding)
{
}

void Terminal::refresh()
{
    if (stream.peek() <= 0)
        return;

    if (stream.peek() == deleteCharacter)
        if (unread.length() > 0)
            unread.remove(unread.length() - 1);

    stream.write(stream.peek());
    unread += (char)stream.peek();
    stream.read();
}

size_t Terminal::write(uint8_t value)
{
    stream.write(value);
}

int Terminal::availableForWrite()
{
    return stream.availableForWrite();
}

int Terminal::available()
{
    return unread.length();
}

int Terminal::read()
{
    if (unread.length() == 0)
        return EOF;
    char c = unread[0];
    unread.remove(0, 1);
    return c;
}

int Terminal::peek()
{
    if (unread.length() == 0)
        return EOF;
    return unread[0];
}
