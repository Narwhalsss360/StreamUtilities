#include "StreamRouters.h"

size_t route(Stream& from, Print& to, size_t count)
{
    size_t routed = 0;
    while (from.available() && from.peek() != EOF && --count)
        to.write(from.read());
    return routed;
}

size_t routeUntil(Stream& from, Print& to, int stop, size_t count)
{
    size_t routed = 0;
    while (from.available() && from.peek() != EOF && from.peek() != stop && --count)
        to.write(from.read());
    return routed;
}