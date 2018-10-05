#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

double sqroot(double n) {
  double g1 = n/2;
  double error = 1.e-6;
  double g2 = (g1 + (n/g1))/2;
  while (g1*g1 != n && abs(g1-g2) > error) {
    g1 = g2;
    g2 = (g1 + (n/g1))/2;
  }
  return g1;
}

int main() {
  cout.precision(numeric_limits<double>::max_digits10);
  cout << sqroot(4) << endl;
  return 0;
}
