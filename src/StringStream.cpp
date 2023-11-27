#include "StringStream.h"
#include "StreamOperators.h"

StringStream::StringStream()
    : Stream(), String(), stringPosition(0), reserved(false)
{
}

StringStream::StringStream(const String& string)
    : Stream(), String(string), stringPosition(0), reserved(false)
{
}

StringStream::StringStream(Stream& stream)
    : Stream(), String(), stringPosition(0), reserved(false)
{
    stream >> this->str();
}

size_t StringStream::write(uint8_t value)
{
    if (!availableForWrite())
        return 0;
    concat(value);
}

int StringStream::availableForWrite()
{
    if (reserved)
        return 1;
    reserved = reserve(length() + 1) == 1;
    return reserved;
}

int StringStream::available()
{
    if (length() == 0)
        return 0;
    return length() - stringPosition - 1;
}

int StringStream::read()
{
    if (available())
        return charAt(++stringPosition);
    return EOF;
}

int StringStream::peek()
{
    if (available())
        return charAt(stringPosition);
    return EOF;
}

size_t StringStream::seek(int32_t offset, int64_t origin)
{
    if (length() == 0)
        return 0;

    switch (origin)
    {
    case ORIGIN_BEGINNING:
        stringPosition = 0;
        break;
    case ORIGIN_END:
        stringPosition = length() - 1;
        break;
    default:
        break;
    }

    stringPosition += offset;

    if (stringPosition >= length())
        stringPosition = length() - 1;
    return stringPosition;
}

size_t StringStream::position()
{
    return stringPosition;
}

String& StringStream::str()
{
    return *this;
}

String& StringStream::str(const String& str)
{
    return ((String&)(*this) = str);
}

Stream& StringStream::stream()
{
    return *this;
}