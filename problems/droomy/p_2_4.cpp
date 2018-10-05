#include <iostream>
using namespace std;

unsigned long long factorial(unsigned long n) {
  unsigned long long result = 1ULL;
  for (unsigned long i = 1; i <= n; ++i) {
    result = result * i;
  }
  return result;
}

double f(double x, unsigned long n) {
  double result = 1.0;
  for (unsigned long i = 1; i <= n; ++i) {
    result = result * x/i;
  }
  return result;
}

bool isFactorial(unsigned int n) {
  int j = 1;
  for (int i = 1; j < n; j = j*i, ++i);
  if (j == n) return true;
  else return false;
}

int main() {
  cout << isFactorial(25) << endl;
  return 0;
}
