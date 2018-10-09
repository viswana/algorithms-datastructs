#include <iostream>
using namespace std;

int smallestDivisor(int n) {
  if (!n) return n;
  if (!(n&1)) return 2;
  int d = 3;
  for (; (n % d) && d*d <= n; d += 2);
  if (!(n%d)) return d;
  else return 1;
}

void printDivisors(int n) {
  for (int i = 1; i*i <= n; ++i) {
    if (!(n%i)) cout << i << ", " << n/i << ", ";
  }
  cout << endl;
}

int main() {
  cout << smallestDivisor(33) << endl;
  printDivisors(33);
  return 0;
}
