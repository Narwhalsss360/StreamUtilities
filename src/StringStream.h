#ifndef StringStream_h
#define StringStream_h

#include "StreamConstants.h"

enum SEEK_ORIGIN : int64_t
{
    ORIGIN_CURRENT = -1,
    ORIGIN_BEGINNING = -2,
    ORIGIN_END = -3
};

class StringStream : public Stream, public String
{
public:
    StringStream();

    StringStream(const String& string);

    StringStream(Stream& stream);

    size_t write(uint8_t value);

    int availableForWrite();

    int available();

    int read();

    int peek();

    size_t seek(int32_t offset, SEEK_ORIGIN origin = ORIGIN_CURRENT);

    size_t position();

    String& str();

    Stream& stream();

private:
    size_t stringPosition;
    bool reserved;
};

#endif
