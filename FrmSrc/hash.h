#ifndef _HASH_H_
#define _HASH_H_


#if defined(_MSC_VER) && (_MSC_VER < 1600)

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef unsigned __int64 uint64_t;


#else   // defined(_MSC_VER)

#include <cstdint>

#endif // !defined(_MSC_VER)

//-----------------------------------------------------------------------------
/// 计算哈希值，三个函数的区别在于返回值和位数不同
void Hash_x86_32  (const void * key, int len, uint32_t seed, void * out );

void Hash_x86_128 (const void * key, int len, uint32_t seed, void * out );

void Hash_x64_128 (const void * key, int len, uint32_t seed, void * out );

//-----------------------------------------------------------------------------

#endif // _HASH_H_
