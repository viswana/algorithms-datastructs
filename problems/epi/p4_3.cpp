#include <iostream>
#include <cassert>
using namespace std;

unsigned long revbits(unsigned long x) {
  x = (x & 0xFFFFFFFF00000000) >> 32 | (x & 0x00000000FFFFFFFF) << 32;
  x = (x & 0xFFFF0000FFFF0000) >> 16 | (x & 0x0000FFFF0000FFFF) << 16;
  x = (x & 0xFF00FF00FF00FF00) >> 8 | (x & 0x00FF00FF00FF00FF) << 8;
  x = (x & 0xF0F0F0F0F0F0F0F0) >> 4 | (x & 0x0F0F0F0F0F0F0F0F) << 4;
  x = (x & 0xCCCCCCCCCCCCCCCC) >> 2 | (x & 0x3333333333333333) << 2;
  x = (x & 0xAAAAAAAAAAAAAAAA) >> 1 | (x & 0x5555555555555555) << 1;
  return x;
}

unsigned long revbits2(unsigned long x) {
  x = (x & 0xAAAAAAAAAAAAAAAA) >> 1 | ((x << 1) & 0xAAAAAAAAAAAAAAAA);
  x = (x & 0xCCCCCCCCCCCCCCCC) >> 2 | ((x << 2) & 0xCCCCCCCCCCCCCCCC);
  x = (x & 0xF0F0F0F0F0F0F0F0) >> 4 | ((x << 4) & 0xF0F0F0F0F0F0F0F0);
  x = (x & 0xFF00FF00FF00FF00) >> 8 | ((x << 8) & 0xFF00FF00FF00FF00);
  x = (x << 48) | (x >> 48) | ((x >> 16) & 0xFFFF0000) | ((x & 0xFFFF0000) << 16);
  return x;
}

int main() {
  cout << hex << revbits(0x01234567) << endl;
  assert(revbits(0x01234567) == revbits2(0x01234567));
  return 0;
}
