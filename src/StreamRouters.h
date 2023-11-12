#ifndef StreamRouting_h
#define StreamRouting_h

#include "StreamConstants.h"

size_t route(Stream& from, Print& to, size_t count = SIZE_MAX);

size_t routeUntil(Stream& from, Print& to, int stop, size_t count = SIZE_MAX);

#endif
