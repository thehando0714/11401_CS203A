
/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/17: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h
    - 2025/11/19: Modified myHashInt function to multiply key by a large prime number 987654361 before %m and myHashString function to sum all character values minus 'a' before %m idea from my c++ version
   Developer: Cheng-Jun Hu chrishu0714@gmail.com
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
   
    unsigned int k = (unsigned int)key; 
    k *= 987654361;
    return (int)(k % m);
    // division method example
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    
    
    for (int i = 0; str[i] != '\0'; i++) {
        hash += str[i] - 'a';
    }
    
    return (int)(hash % m); 
}