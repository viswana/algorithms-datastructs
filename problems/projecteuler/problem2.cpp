#include <iostream>
using namespace std;

int main() {
  int fib1 = 1;
  int fib2 = 1;
  int sum = 0;
  while (fib2 < 90) {
    if (!(fib2 & 1)) sum+= fib2;
    int fib = fib1 + fib2;
    fib1 = fib2;
    fib2 = fib;
  }
  cout << sum << endl;
}
