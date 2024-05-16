#if !defined(YieldReaders_h) && __has_include(<SketchBinder.h>)
#define YieldReaders_h

#include <StreamConstants.h>
#include <Binds.h>

namespace StreamReaders {
    int yieldedPeek(Stream& stream);

    int yieldingPeek(Stream& stream);

    int yieldedRead(Stream& stream);

    int yieldingRead(Stream& stream);
}

#endif
