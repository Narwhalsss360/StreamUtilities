#include "StreamOperators.h"
#include "StreamReaders.h"
#include <NFuncs.h>

#pragma region BitShift Left
Print& operator<<(Print& stream, const unsigned char& value)
{
    stream.print(value);
    return stream;
}

Print& operator<<(Print& stream, const char& value)
{
    stream.print(value);
    return stream;
}

Print& operator<<(Print& stream, const unsigned short& value)
{
    stream.print(value);
    return stream;
}

Print& operator<<(Print& stream, const short& value)
{
    stream.print(value);
    return stream;
}

Print& operator<<(Print& stream, const unsigned int& value)
{
    stream.print(value);
    return stream;
}

Print& operator<<(Print& stream, const int& value)
{
    stream.print(value);
    return stream;
}

Print& operator<<(Print& stream, const unsigned long& value)
{
    stream.print(value);
    return stream;
}

Print& operator<<(Print& stream, const long& value)
{
    stream.print(value);
    return stream;
}

Print& operator<<(Print& stream, const unsigned long long& value)
{
    stream.print(ulltostr(value));
    return stream;
}

Print& operator<<(Print& stream, const long long& value)
{
    if (value < 0)
    {
        stream << '-';
        stream << (unsigned long long)(-1 * value);
    }
    else
    {
        stream << (unsigned long long)value;
    }
    return stream;
}

Print& operator<<(Print& stream, const double& value)
{
    stream.print(value);
    return stream;
}

Print& operator<<(Print& stream, const String& value)
{
    stream.print(value);
    return stream;
}

Print& operator<<(Print& stream, const Printable& value)
{
    stream.print(value);
    return stream;
}

Print& operator<<(Print& stream, Print& (*manipulator)(Print&))
{
    return manipulator(stream);
}
#pragma endregion

#pragma region BitShift Right
Stream& operator>>(Stream& stream, unsigned char& value)
{
    if (!stream.available() || stream.peek() == EOF)
        value = '\0';
    else
        value = stream.read();
    return stream;
}

Stream& operator>>(Stream& stream, char& value)
{
    if (!stream.available() || stream.peek() == EOF)
        value = '\0';
    else
        value = stream.read();
    return stream;
}

Stream& operator>>(Stream& stream, unsigned short& value)
{
    String read;
    stream >> read;
    for (const char& c : read)
    {
        if (!isDigit(c))
        {
            return stream;
        }
    }

    value = atoi(read.c_str());
    return stream;
}

Stream& operator>>(Stream& stream, short& value)
{
    String read;
    stream >> read;
    for (const char& c : read)
    {
        if (!isDigit(c))
        {
            return stream;
        }
    }

    value = atoi(read.c_str());
    return stream;
}

Stream& operator>>(Stream& stream, unsigned int& value)
{
    String read;
    stream >> read;
    for (const char& c : read)
    {
        if (!isDigit(c))
        {
            return stream;
        }
    }

    value = atoi(read.c_str());
    return stream;
}

Stream& operator>>(Stream& stream, int& value)
{
    String read;
    stream >> read;
    for (const char& c : read)
    {
        if (!isDigit(c))
        {
            return stream;
        }
    }

    value = atoi(read.c_str()); 
    return stream;
}

Stream& operator>>(Stream& stream, unsigned long& value)
{
    String read;
    stream >> read;
    for (const char& c : read)
    {
        if (!isDigit(c))
        {
            return stream;
        }
    }

    value = atol(read.c_str());
    return stream;
}

Stream& operator>>(Stream& stream, long& value)
{
    String read;
    stream >> read;
    for (const char& c : read)
    {
        if (!isDigit(c))
        {
            return stream;
        }
    }

    value = atol(read.c_str());
    return stream;
}

Stream& operator>>(Stream& stream, unsigned long long& value)
{
    String read;
    stream >> read;
    for (const char& c : read)
    {
        if (!isDigit(c))
        {
            return stream;
        }
    }

    value = atol(read.c_str());
    return stream;
}

Stream& operator>>(Stream& stream, long long& value)
{
    String read;
    stream >> read;
    for (const char& c : read)
    {
        if (!isDigit(c))
        {
            return stream;
        }
    }

    value = atol(read.c_str());
    return stream;
}

Stream& operator>>(Stream& stream, double& value)
{
    String read = stream.readStringUntil(' ');
    value = atof(read.c_str());
    return stream;
}

Stream& operator>>(Stream& stream, String& value)
{
    value = readUntil(stream, ' ', BLOCKING, 8);
    return stream;
}
#pragma endregion