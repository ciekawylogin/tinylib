#include "Encrypt.h"
#include <cstdlib>
#include <iostream>

constexpr int Encrypt::primes[10];

Encrypt::Encrypt()
{}



std::pair<std::pair<int,int>,std::pair<int,int>> Encrypt::getAsymKeys()
{
    int p,q,phi,n,e,d;
    do
    {
       srand(time(NULL));
    do
      {
        p = primes[rand() % 10];
        q = primes[rand() % 10];
      } while (p == q);

      phi = (p - 1) * (q - 1);
      n   = p * q;

    // wyznaczamy wykładniki e i d

      for(e = 3; gcd(e,phi) != 1; e += 2);
      d = reverseMod(e,phi);

    }while(d==e || n==0);
      //e, n publiczny
      //d, n prywatny
      return std::make_pair(std::make_pair(e,n),std::make_pair(d,n));
}

void Encrypt::symCrypt(char *buf, int num, char key)
{
    for(int i = 0; i < num; i++)
    {
        buf[i]=buf[i]^key;
    }
}


//najpierw n, potem e lub d

int Encrypt::asymCrypt(int data, int w, int n)
{
  int pow,res,q;

// wykładnik w rozbieramy na sumę potęg 2
// przy pomocy algorytmu Hornera. Dla reszt
// niezerowych tworzymy iloczyn potęg a modulo n.

  pow = data; res = 1;
  for(q = w; q > 0; q /= 2)
  {
    if(q % 2) res = (res * pow) % n;
    pow = (pow * pow) % n; // kolejna potęga
  }
  return res;
}


int Encrypt::gcd(int a, int b)
{
  int t;

  while(b != 0)
  {
    t = b;
    b = a % b;
    a = t;
  };
  return a;
}

int Encrypt::reverseMod(int a, int n)
{
  int a0,n0,p0,p1,q,r,t;

  p0 = 0; p1 = 1; a0 = a; n0 = n;
  q  = n0 / a0;
  r  = n0 % a0;
  while(r > 0)
  {
    t = p0 - q * p1;
    if(t >= 0)
      t = t % n;
    else
      t = n - ((-t) % n);
    p0 = p1; p1 = t;
    n0 = a0; a0 = r;
    q  = n0 / a0;
    r  = n0 % a0;
  }
  return p1;
}



