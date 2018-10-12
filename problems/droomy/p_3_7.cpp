#include <iostream>
#include <vector>
using namespace std;

unsigned long exp(unsigned int x, unsigned int n) {
  if (n == 0) return 1;
  else if (n == 1) return x;
  if (n & 1) {
    return x * exp(x, (n-1)>>1) * exp(x, (n-1)>>1);
  }
  else {
    return exp(x, n>>1) * exp(x, n>>1);
  }
}

unsigned long exp1(unsigned int x, unsigned int n) {
  vector<unsigned int> a;
  while(n > 0) {
    a.push_back(n&1);
    n >>= 1;
  }
  unsigned long p = 1;
  for (int i = a.size()-1; i >= 0; i--) {
    if (a[i]) p = p*p*x;
    else p = p*p;
  }
  return p;
}

unsigned long exp2(unsigned int x, unsigned int n) {
  unsigned long p = 1;
  unsigned long placevalue = x;
  while (n > 0) {
    if (n & 1) {
      p = p * placevalue;
    }
    placevalue *= placevalue;
    n >>= 1;
  }
  return p;
}

unsigned long expb3(unsigned int x, unsigned int n) {
  unsigned long p = 1;
  unsigned long placevalue = x;
  while (n > 0) {
    if ((n % 3) == 2) {
      p = p * placevalue * placevalue;
    }
    else if ((n % 3) == 1) {
      p = p * placevalue;
    }
    n = n/3;
    placevalue = placevalue * placevalue * placevalue;
  }
  return p;
}

bool isPrime(unsigned char n) {
  if (n == 2) return true;
  return exp2(2, n-1) % n == 1; 
}

int main() {
  cout << expb3(2, 16) << endl;
  cout << isPrime(19) << endl;
  return 0;
}
