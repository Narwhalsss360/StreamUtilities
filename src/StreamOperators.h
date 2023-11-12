#ifndef StreamOperators_h
#define StreamOperators_h

#include "StreamConstants.h"
#include "StreamRouters.h"
#include <NFuncs.h>

#pragma region BitShift Left
Stream& operator<<(Stream& stream, uint32_t value);

Stream& operator<<(Stream& stream, int32_t value);

Stream& operator<<(Stream& stream, int64_t value);

Stream& operator<<(Stream& stream, uint64_t value);

Stream& operator<<(Stream& stream, double value);

Stream& operator<<(Stream& stream, char value);

Stream& operator<<(Stream& stream, const String& value);

Stream& operator<<(Stream& stream, const Printable& value);
#pragma endregion

#pragma region BitShift Right
Stream& operator>>(Stream& stream, uint32_t& value);

Stream& operator>>(Stream& stream, int32_t& value);

Stream& operator>>(Stream& stream, int64_t& value);

Stream& operator>>(Stream& stream, uint64_t& value);

Stream& operator>>(Stream& stream, double& value);

Stream& operator>>(Stream& stream, char& value);

Stream& operator>>(Stream& stream, String& value);
#pragma endregion

#endif
