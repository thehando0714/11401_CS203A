
/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/17: Initial implementation
    - 2025/11/17: Modified myHashString function use first letter minus 'a' then %m 
    - 2025/11/17: Modified myHashInt function to multiply key by a prime number 13 before %m
   Developer: Cheng-Jun Hu chrishu0714@gmail.com
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    key*=13;
    return key % m;  // basic division method
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    hash=str[0]-'a';
    // TODO: replace with your own design
    return static_cast<int>(hash % m);  // basic division method
}