#include "YieldReaders.h"
#ifdef YieldReaders_h

namespace StreamReaders
{
    using namespace binds;

    int yieldedPeek(Stream& stream)
    {
        if (!ranSetup())
            return stream.peek();

        int peeked = stream.peek();
        if (peeked < 0)
        {
            loop_pre();
            peeked = stream.peek();
            loop_post();
        }
        return peeked;
    }

    int yieldingPeek(Stream& stream)
    {
        int peeked;
        do
        {
            if (ranSetup())
                loop_pre();
            peeked = stream.peek();
            if (ranSetup())
                loop_post();
        } while (peeked < 0);
    }

    int yieldedRead(Stream& stream)
    {
        if (!ranSetup())
            return stream.read();

        int peeked = stream.read();
        if (peeked < 0)
        {
            loop_pre();
            peeked = stream.read();
            loop_post();
        }
        return peeked;
    }

    int yieldingRead(Stream& stream)
    {
        int peeked;
        do
        {
            if (ranSetup())
                loop_pre();
            peeked = stream.read();
            if (ranSetup())
                loop_post();
        } while (peeked < 0);
    }
}

#endif