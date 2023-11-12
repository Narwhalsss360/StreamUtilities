#include "StreamOperators.h"

#pragma region BitShift Left
Stream& operator<<(Stream& stream, uint32_t value)
{
    stream.print(value);
    return stream;
}

Stream& operator<<(Stream& stream, int32_t value)
{
    stream.print(value);
    return stream;
}

Stream& operator<<(Stream& stream, int64_t value)
{
    if (value < 0)
        stream.write('-');
    stream.print(ulltostr(labs(value)));
    return stream;
}

Stream& operator<<(Stream& stream, uint64_t value)
{
    stream.print(ulltostr(value));
    return stream;
}

Stream& operator<<(Stream& stream, double value)
{
    stream.print(value);
    return stream;
}

Stream& operator<<(Stream& stream, char value)
{
    stream.print(value);
    return stream;
}

Stream& operator<<(Stream& stream, const String& value)
{
    stream.print(value);
    return stream;
}

Stream& operator<<(Stream& stream, const Printable& value)
{
    stream.print(value);
    return stream;
}

#pragma endregion

#pragma region BitShift Right
Stream& operator>>(Stream& stream, uint32_t& value)
{
    String read = stream.readStringUntil(' ');
    value = atol(read.c_str());
    return stream;
}

Stream& operator>>(Stream& stream, int32_t& value)
{
    String read = stream.readStringUntil(' ');
    value = atol(read.c_str());
    return stream;
}

Stream& operator>>(Stream& stream, int64_t& value)
{
    String read = stream.readStringUntil(' ');
    value = atol(read.c_str());
    return stream;
}

Stream& operator>>(Stream& stream, uint64_t& value)
{
    String read = stream.readStringUntil(' ');
    value = atol(read.c_str());
    return stream;
}

Stream& operator>>(Stream& stream, double& value)
{
    String read = stream.readStringUntil(' ');
    value = atof(read.c_str());
    return stream;
}

Stream& operator>>(Stream& stream, char& value)
{
    value = stream.read();
    return stream;
}

Stream& operator>>(Stream& stream, String& value)
{
    value = stream.readStringUntil(' ');
    return stream;
}
#pragma endregion