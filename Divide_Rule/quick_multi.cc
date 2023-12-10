#include <iostream>
/// @brief 
/// @param base 
/// @param exp must be positive 
/// @param mod 
/// @return 
long long pow(long long base, int exp, int mod) {
    long long res = 1;
    for (; exp; exp /= 2) {
        if (exp % 2) res = res * base % mod;
        base = base * base % mod;
    }
    return res;
}