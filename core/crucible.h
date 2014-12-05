/* 
* File:   crucible.h
* Author: Matt Lynam <lynam.matt@gmail.com>
*
* Created on December 2, 2014
* 
* The MIT License (MIT)
*
* Copyright (c) December 2, 2014 Matt Lynam <lynam.matt@gmail.com>
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#ifndef CRUCIBLE_H
#define	CRUCIBLE_H

#include <cstdint>

namespace crucible {
namespace engine {
namespace core {

// platform
#if defined(_WIN32) || defined(_WIN64)
#ifdef _WIN64
#define ENVIRONMENT64
#else // !_WIN64
#define ENVIRONMENT32
#endif // _WIN64
#endif // _WIN32 || _WIN64
#ifdef __GNUC__
#if defined(__x86_64__) || defined(__ppc64__)
#define ENVIRONMENT64
#else // !__x86_64__ && !__ppc64__
#define ENVIRONMENT32
#endif
#endif

#ifdef ENVIRONMENT64

// 64bit platform typedefs
typedef std::int64_t Int;
typedef std::uint64_t UInt;
// end 64bit platform typedefs

#elif defined(ENVIRONMENT32)

// 32bit platform typedefs
typedef std::int32_t Int;
typedef std::uint32_t UInt;
// end 32bit platform typedefs

#endif

// modify this value to provide more or less components in the engine.
// the total number of component allowed is:
// kMaxComponentBuckets * sizeof(UInt) * 8.
const UInt kMaxComponentBuckets = 64;

} // namespace core
} // namespace engine
} // namespace crucible

#endif	/* CRUCIBLE_H */