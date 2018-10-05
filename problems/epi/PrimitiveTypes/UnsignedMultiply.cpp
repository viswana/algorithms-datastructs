#include <iostream>
#include <limits>
using namespace std;

unsigned long long Add(unsigned long long a, unsigned long long b) {
  unsigned long long ci = 0, place = 1, tempa = a, tempb = b, co = 0, sum = 0;
  while (tempa || tempb) {
    unsigned long long ak = a & place;
    unsigned long long bk = b & place;
    sum = sum | ((ak ^ bk) ^ ci);
    co = (ci & (ak ^ bk)) + (ak & bk);
    ci = co << 1;
    place <<= 1;
    tempa >>= 1;
    tempb >>= 1;
  }
  return sum | ci;
}

unsigned long long Multiply(unsigned int a, unsigned int b) {
  unsigned long long sum = 0;
  if (!a || !b) return sum;
  unsigned int tempa = a;
  unsigned int tempb = b;
  unsigned int cta = 0, ctb = 0;
  while (tempa) {
    tempa = tempa & (tempa-1);
    cta++;
  }
  while (tempb) {
    tempb = tempb & (tempb-1);
    ctb++;
  }
  if (cta < ctb) {
    unsigned int temp = a;
    a = b;
    b = temp;
  }
  unsigned int place = 0;
  while (b) {
    if (b & 1) {
      sum = Add(sum, (unsigned long long)a << place);
    }
    place++;
    b >>= 1;
  }
  return sum;
}

int main() {
  cout << Multiply(numeric_limits<unsigned int>::max(),
		   numeric_limits<unsigned int>::max()) << endl;
  return 0;
}
