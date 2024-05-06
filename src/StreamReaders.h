#ifndef StreamReaders_h
#define StreamReaders_h

#include "StreamConstants.h"
#include <WString.h>

static constexpr bool BLOCKING = true;
static constexpr bool NON_BLOCKING = false;
static constexpr int NON_STOPPING = -2;

size_t getLine(Stream& stream, String& string, bool block = BLOCKING);

template <typename iterator>
size_t readInto(Stream& stream, iterator begin, iterator end, int stop = EOF, size_t count = SIZE_MAX)
{
    size_t read = 0;
    while ((stop == NON_STOPPING ? true : (stream.available() && stream.peek() != stop)) && --count && begin != end)
    {
        *begin = stream.read();
        read++;
        ++begin;
    }
    return read;
}

String readAll(Stream& stream, uint32_t interReadDelayus);

String readUntil(Stream& stream, char terminator, bool block = NON_BLOCKING, unsigned int interReadDelayus = 0);

String readUntil(Stream& stream, char* terminators, size_t terminatorCount, bool block, unsigned int interReadDelayus);

#endif
