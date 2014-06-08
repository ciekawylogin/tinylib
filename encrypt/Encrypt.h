#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <utility>

class Encrypt
{
public:
    Encrypt();
    static std::pair<std::pair<int,int>,std::pair<int,int>> getAsymKeys();
    static int asymCrypt(int,int,int);
    static void symCrypt(char *, int, char);
private:
    static int gcd(int,int);
    static int reverseMod(int,int);
    static int powerMod(int,int,int);

    static constexpr int primes[10] = {	13, 17, 19, 23, 29, 31, 37, 41, 43 };

};

#endif // ENCRYPT_H

