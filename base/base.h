#pragma once

#ifdef _MSC_VER
#include <intrin.h>
#endif

#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <ctime>
#include <thread>
#include <utility>

#define __ASSERT(a) assert(a)
#define __ASSERT_BOUND(a, b, c) assert((a) <= (b) && (b) <= (c))
#define __ASSERT_BOUND_2(a, b, c, d) assert((a) <= (b) && (b) <= (c) && (c) <= (d))

inline bool EQV(bool bArg1, bool bArg2)
{
    return bArg1 ? bArg2 : !bArg2;
}

inline bool XOR(bool bArg1, bool bArg2)
{
    return bArg1 ? !bArg2 : bArg2;
}

template <typename T>
inline T ABS(T Arg)
{
    return Arg < 0 ? -Arg : Arg;
}

template <typename T>
inline T SQR(T Arg)
{
    return Arg * Arg;
}

template <typename T>
inline int PopCnt(T n)
{
#ifdef _MSC_VER
    return __popcount(n);
#elif __GNUC__
    return __builtin_popcountll(n);
#else
#error "Not implemented"
#endif
}

inline int64_t GetTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}
