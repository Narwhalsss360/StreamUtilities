#include "StreamReaders.h"
#include <Arduino.h>

size_t getLine(Stream& stream, String& string, bool blocking)
{
    while (stream.peek() != '\n' && (blocking || (stream.available() && stream.peek() != EOF)))
        string += stream.read();
    return string.length();
}

String readAll(Stream& stream, uint32_t interReadDelayus)
{
    String string;
    while (stream.available() && stream.peek() != EOF)
    {
        string += (char)stream.read();
        delayMicroseconds(interReadDelayus);
    }
    return string;
}

String readUntil(Stream& stream, char terminator, bool block, unsigned int interReadDelayus)
{
    while (!stream.available() && block);
    delay(interReadDelayus * 2);
    String read;
    while (stream.available() && stream.peek() != EOF && stream.peek() != terminator)
    {
        delayMicroseconds(interReadDelayus);
        read += (char)stream.read();
    }
    return read;
}
