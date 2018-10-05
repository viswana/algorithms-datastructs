#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

double msin(double x) {
  double error = 1.0e-15;
  double tsin = 0;
  double term = x;
  double xsq = x*x;
  int i = 1;
  while (abs(term) > error) {
    tsin += term;
    i += 2;
    term = -term*xsq/(i*(i-1));
  }
  return tsin;
}

double mcos(double x) {
  double error = 1.0e-15;
  double tsin = 0;
  double term = 1;
  double xsq = x*x;
  int i = 0;
  while (abs(term) > error) {
    tsin += term;
    i += 2;
    term = -term*xsq/(i*(i-1));
  }
  return tsin;
}

unsigned long long sumtonfact(unsigned long n) {
  if (!n) return 0;
  unsigned long long sum = 0;
  unsigned long i = 1;
  unsigned long long term = 1;
  while (i < n) {
    term = term*i;
    sum = sum + term;
    ++i;
  }
  return sum+1;
}

double euler(unsigned int n) {
  if (!n) return 0;
  double sum = 0;
  double term = 1;
  for (int i = 1; i < n; ++i) {
    term = term*1/i;
    sum = sum + term;
  }
  return sum+1;
}

int main() {
  cout.precision(numeric_limits<double>::max_digits10);
  cout << atan(1) << endl;
  cout << msin(atan(1)) << endl;
  cout << mcos(atan(1)) << endl;
  cout << sumtonfact(5) << endl;
  cout << euler(15) << endl;
  return 0;
}
