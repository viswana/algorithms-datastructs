#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
using namespace std;

double sqroot(double n) {
  double g2 = n/2;
  double g1;
  double error = 1.e-6;
  do {
    //cout << g2 << endl;
    g1 = g2;
    g2 = (g1 + (n/g1))/2;
  } while(abs(g1-g2) > error);
  return g2;
}

unsigned int intsqrt(unsigned int n) {
  unsigned int g1 = n/2;
  unsigned int g2 = (g1 + n/g1)/2;
  while (g1*g1 > n) {
    g1 = g2;
    g2 = (g1 + n/g1)/2;
  }
  return g1 + 1;
}

double reciprocal(double n) {
  double g2 = 1;
  double g1;
  double error = 1e-6;
  do {
    g1 = g2;
    g2 = (g1 + 1/(n*n*g1))/2;
  } while (abs(g1-g2) > error);
  return g2;
}

double nthRoot(double k, unsigned int n) {
  double g2 = k/n;
  double error = 1e-9;
  double g1;
  do {
    g1 = g2;
    g2 = ((n-1)*g1 + k/pow(g1, n-1))/n;
  } while (abs(g1-g2) > error);
  return g2;
}

double geometricMean(vector<double> x) {
  double result = 1.0;
  for (auto i : x) {
    result = result * nthRoot(i, x.size());
  }
  return result;
}


int main() {
  cout.precision(numeric_limits<double>::max_digits10);
  //sqroot(0.25);
  //cout << reciprocal(4) << endl;
  //reciprocal(4);
  cout << nthRoot(27, 3) << endl;
  //cout << intsqrt(40) << endl;
  //cout << reciprocal(5) << endl;
  return 0;
}
