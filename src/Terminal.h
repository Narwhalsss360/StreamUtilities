#ifndef Terminal_h
#define Terminal_h

#include "StreamConstants.h"

class Terminal : public Stream
{
public:
    Terminal(Stream& stream, size_t maxBufferSize = SIZE_MAX, char deleteCharacter = 0x7F, const char* lineEnding = "\r\n");

    void refresh();

    size_t write(uint8_t value);

    int availableForWrite();

    int available();

    int read();

    int peek();

private:
    Stream& stream;
    String unread;
    const size_t maxBufferSize;
    const char deleteCharacter;
    const char* lineEnding;
};

#endif
