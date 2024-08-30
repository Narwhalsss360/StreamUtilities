#include "StreamReaders.h"
#include <Arduino.h>

namespace StreamReaders
{
    int peek(Stream& stream)
    {
        return stream.peek();
    }

    int read(Stream& stream)
    {
        return stream.read();
    }

    int timedPeek(Stream& stream)
    {
        int c;
        unsigned long start = millis();
        do
        {
            c = stream.peek();
            if (c >= 0)
                return c;
        } while (millis() - start < stream.getTimeout());
        stream.read();
        return c;
    }

    int timedRead(Stream& stream)
    {
        int c;
        unsigned long start = millis();
        do
        {
            c = stream.read();
            if (c >= 0)
                return c;
        } while (millis() - start < stream.getTimeout());
        stream.read();
        return c;
    }

    int blockingPeek(Stream& stream)
    {
        int c;
        do
        {
            c = stream.peek();
            if (c >= 0)
                return c;
        } while (true);
    }

    int blockingRead(Stream& stream)
    {
        int c;
        do
        {
            c = stream.read();
            if (c >= 0)
                return c;
        } while (true);
    }
}

using namespace StreamReaders;

size_t getLine(Stream& stream, String& string, Reader reader, Peeker peeker)
{
    size_t count = 0;
    while (peeker(stream) != '\n' && peeker(stream) >= 0)
    {
        string += reader(stream);
        count++;
    }
    return count;
}

String readAll(Stream& stream, Reader reader, Peeker peeker)
{
    String string;
    while (peeker(stream) >= 0)
        string += (char)reader(stream);
    return string;
}

static bool contains(char* array, size_t size, char item)
{
    for (size_t i = 0; i < size; i++)
        if (array[i] == item)
            return true;
    return false;
}

String readUntil(Stream& stream, char* terminators, size_t terminatorCount, Reader reader, Peeker peeker)
{
    String read;
    while (peeker(stream) >= 0 && !contains(terminators, terminatorCount, peeker(stream)))
        read += (char)reader(stream);
    return read;
}

String readUntil(Stream& stream, bool (*stopPredicate)(int), StreamReaders::Reader reader, StreamReaders::Peeker peeker)
{
    String read;
    while (!stopPredicate(peeker(stream)))
        read += (char)reader(stream);
    return read;
}

String readUntil(Stream& stream, bool (*stopPredicate)(int), bool (*accept)(int), StreamReaders::Reader reader, StreamReaders::Peeker peeker)
{
    String read;
    do
    {
        if (accept(peeker(stream)))
            read += (char)reader(stream);
        else
            reader(stream);
    } while (!stopPredicate(peeker(stream)));

    return read;
}
