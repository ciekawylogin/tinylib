#include "encrypt.h"

Encrypt::Encrypt()
{}

static std::pair<std::pair<int,int>,std::pair<int,int>> Encrypt::getKeys()
{
    int p,q,phi,n,e,d;

    do
      {
        p = primes[rand() % 1000];
        q = primes[rand() % 1000];
      } while (p == q);

      phi = (p - 1) * (q - 1);
      n   = p * q;

    // wyznaczamy wykładniki e i d

      for(e = 3; gcd(e,phi) != 1; e += 2);
      d = reverseMod(e,phi);
      //n, e publiczny
      //n, d prywatny
      return std::pair<std::pair<n, e>, std::pair<n, d>>;
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

int Encrypt::powerMod(int a, int w, int n)
{
  int pow,res,q;

// wykładnik w rozbieramy na sumę potęg 2
// przy pomocy algorytmu Hornera. Dla reszt
// niezerowych tworzymy iloczyn potęg a modulo n.

  pow = a; res = 1;
  for(q = w; q > 0; q /= 2)
  {
    if(q % 2) res = (res * pow) % n;
    pow = (pow * pow) % n; // kolejna potęga
  }
  return res;
}

static Encrypt::std::pair<char*,int> encrypt(char* buf,int num)
{
    char *res;

}

static std::pair<char*,int> decrypt(char*,int);
