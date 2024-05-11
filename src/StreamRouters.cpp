#include "StreamRouters.h"

using namespace StreamReaders;

size_t route(Stream& from, Print& to, size_t count, Reader reader, Peeker peeker)
{
    size_t routed = 0;
    while (peeker(from) >= 0 && --count)
    {
        to.write(reader(from));
        if (to.getWriteError())
        {
            return routed;
        }
    }
    return routed;
}

size_t routeUntil(Stream& from, Print& to, int stop, size_t count, Reader reader, Peeker peeker)
{
    size_t routed = 0;
    while (peeker(from) >= 0 && peeker(from) != stop && --count)
    {
        to.write(reader(from));
        if (to.getWriteError())
        {
            return routed;
        }
    }
    return routed;
}
