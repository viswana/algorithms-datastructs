#include <iostream>
using namespace std;

void lucas(unsigned int n) {
  unsigned int a = 1;
  unsigned int b = 3;
  unsigned int i = 0;
  for (; i < n-1; i += 2) {
    cout << a << ", " << b << ", ";
    a = a+b;
    b = a+b;
  }
  if (i == n-1) cout << a;
  cout << endl;
}

void seqSumAdjFact(unsigned int n) {
  unsigned long long a = 1;
  unsigned long long b = 1;
  for (unsigned int i = 0; i < n; ++i) {
    cout << a + b << ", ";
    a = b;
    b = b*(i+2);
  }
  cout << endl;
}

int main() {
  lucas(6);
  seqSumAdjFact(15);
  return 0;
}
