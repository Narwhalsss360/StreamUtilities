#ifndef StreamRouting_h
#define StreamRouting_h

#include "StreamConstants.h"
#include "StreamReaders.h"

size_t route(Stream& from, Print& to, size_t count = SIZE_MAX, StreamReaders::Reader reader = StreamReaders::read, StreamReaders::Peeker peeker = StreamReaders::timedPeek);

size_t routeUntil(Stream& from, Print& to, int stop, size_t count = SIZE_MAX, StreamReaders::Reader reader = StreamReaders::read, StreamReaders::Peeker peeker = StreamReaders::timedPeek);

#endif
