#ifndef StreamOperators_h
#define StreamOperators_h

#include "StreamConstants.h"

#pragma region BitShift Left
Stream& operator<<(Stream& stream, const unsigned char& value);

Stream& operator<<(Stream& stream, const char& value);

Stream& operator<<(Stream& stream, const unsigned short& value);

Stream& operator<<(Stream& stream, const short& value);

Stream& operator<<(Stream& stream, const unsigned int& value);

Stream& operator<<(Stream& stream, const int& value);

Stream& operator<<(Stream& stream, const unsigned long& value);

Stream& operator<<(Stream& stream, const long& value);

Stream& operator<<(Stream& stream, const unsigned long long& value);

Stream& operator<<(Stream& stream, const long long& value);

Stream& operator<<(Stream& stream, const double& value);

Stream& operator<<(Stream& stream, const String& value);

Stream& operator<<(Stream& stream, const Printable& value);
#pragma endregion

#pragma region BitShift Right
Stream& operator>>(Stream& stream, unsigned char& value);

Stream& operator>>(Stream& stream, char& value);

Stream& operator>>(Stream& stream, unsigned short& value);

Stream& operator>>(Stream& stream, short& value);

Stream& operator>>(Stream& stream, unsigned int& value);

Stream& operator>>(Stream& stream, int& value);

Stream& operator>>(Stream& stream, unsigned long& value);

Stream& operator>>(Stream& stream, long& value);

Stream& operator>>(Stream& stream, unsigned long long& value);

Stream& operator>>(Stream& stream, long long& value);

Stream& operator>>(Stream& stream, double& value);

Stream& operator>>(Stream& stream, String& value);
#pragma endregion

#endif
