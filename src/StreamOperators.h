#ifndef StreamOperators_h
#define StreamOperators_h

#include "StreamConstants.h"
#include "StreamReaders.h"

#pragma region BitShift Left
Print& operator<<(Print& stream, const unsigned char& value);

Print& operator<<(Print& stream, const char& value);

Print& operator<<(Print& stream, const unsigned short& value);

Print& operator<<(Print& stream, const short& value);

Print& operator<<(Print& stream, const unsigned int& value);

Print& operator<<(Print& stream, const int& value);

Print& operator<<(Print& stream, const unsigned long& value);

Print& operator<<(Print& stream, const long& value);

Print& operator<<(Print& stream, const unsigned long long& value);

Print& operator<<(Print& stream, const long long& value);

Print& operator<<(Print& stream, const double& value);

Print& operator<<(Print& stream, const String& value);

Print& operator<<(Print& stream, const Printable& value);

Print& operator<<(Print& stream, Print& (*manipulator)(Print&));
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

extern StreamReaders::Reader OperatorReader;

extern StreamReaders::Peeker OperatorPeeker;

Stream& operator>>(Stream& stream, String& value);
#pragma endregion

#endif
