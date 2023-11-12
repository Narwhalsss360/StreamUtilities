#include "StreamReaders.h"

size_t getLine(Stream& stream, String& string, bool blocking)
{
    while (stream.peek() != '\n' && (blocking || (stream.available() && stream.peek() != EOF)))
        string += stream.read();
    return string.length();
}