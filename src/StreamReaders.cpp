#include "StreamReaders.h"
#include <Arduino.h>

size_t getLine(Stream& stream, String& string, bool blocking)
{
    while (stream.peek() != '\n' && (blocking || (stream.available() && stream.peek() != EOF)))
        string += stream.read();
    return string.length();
}

inline String readAll(Stream& stream, uint32_t interReadDelayus)
{
    String string;
    while (stream.available() && stream.peek() != EOF)
    {
        string += (char)stream.read();
        delayMicroseconds(interReadDelayus);
    }
    return string;
}