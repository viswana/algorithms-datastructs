#include <iostream>
#include <cassert>
using namespace std;

unsigned char parity(unsigned long x) {
  x ^= x >> 32;
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return x & 1;
}

//1010000 => 1011111
unsigned long rightproprmb(unsigned long x) {
  return x | (x-1);
}

// 77 mod 64 = 13
unsigned long modp2(unsigned long x, unsigned long m) {
  return x & (m-1);
}

bool isp2(unsigned long x) {
  return (x & (x-1)) == 0;
}


int main() {
  assert(isp2(64));
  assert(!isp2(77));
  assert(modp2(77, 64) == 13);
  assert(rightproprmb(0x50) == 0x5f);
  return 0;
}
