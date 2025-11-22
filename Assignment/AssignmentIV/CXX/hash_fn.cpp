
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
    - 2025/11/19: Modified myHashInt function to multiply key by a large prime number 987654361 before %m and myHashString function to sum all character values minus 'a' before %m
   Developer: Cheng-Jun Hu chrishu0714@gmail.com
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    
    //key*=13;
    unsigned int k=key;
    k*=987654361;
    return k % m;  // basic division method
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    //hash=str[0]-'a';
    for(int i=0;i<str.size();i++){
        hash+=str[i]-'a';
    }
    
    return static_cast<int>(hash % m);  // basic division method
}