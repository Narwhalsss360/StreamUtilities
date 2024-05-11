#ifndef StreamReaders_h
#define StreamReaders_h

#include "StreamConstants.h"
#include <WString.h>

namespace StreamReaders
{
    using Reader = int (*)(Stream&);

    using Peeker = int (*)(Stream&);

    int peek(Stream& stream);

    int read(Stream& stream);

    int timedPeek(Stream& stream);

    int timedRead(Stream& stream);

    int blockingPeek(Stream& stream);

    int blockingRead(Stream& stream);

    const constexpr Reader DEFAULT_READER = read;

    const constexpr Peeker DEFAULT_PEEKER = timedPeek;
}

size_t getLine(Stream& stream, String& string, StreamReaders::Reader reader = StreamReaders::read, StreamReaders::Peeker peeker = StreamReaders::blockingPeek);

String readAll(Stream& stream, StreamReaders::Reader reader = StreamReaders::read, StreamReaders::Peeker peeker = StreamReaders::timedPeek);

String readUntil(Stream& stream, char* terminators, size_t terminatorCount, StreamReaders::Reader reader = StreamReaders::read, StreamReaders::Peeker peeker = StreamReaders::timedPeek);

String readUntil(Stream& stream, bool (*stopPredicate)(int), StreamReaders::Reader reader = StreamReaders::read, StreamReaders::Peeker peeker = StreamReaders::blockingPeek);

String readUntil(Stream& stream, bool (*stopPredicate)(int), bool (*accept)(int), StreamReaders::Reader reader = StreamReaders::read, StreamReaders::Peeker peeker = StreamReaders::blockingPeek);

#endif
