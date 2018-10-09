#include <iostream>
#include <vector>
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

unsigned int largestFactorialFactor(unsigned int n) {
  if (n%2) return 1;
  unsigned int ret = 1;
  for (unsigned int j = 1, i = 2; j <= n; j = j*i, ++i) {
    if (!(n%j)) ret = j;
  }
  return ret;
}

int multiplyByAdd(int x, int y) {
  if (x == 0 || y == 0) return 0;
  int a = (x < 0) ? -x : x;
  int b = (y < 0) ? -y : y;
  if (b < a) {
    int t = a;
    a = b;
    b = t;
  }
  int ret = 0;
  for (int i = 0; i < a; ++i, ret += b);
  if ((x < 0) ^ (y < 0)) ret = -ret;
  return ret;
}

unsigned int binomialCoeffHelper(unsigned int n, unsigned int r) {
  if (r == 0 || r == n) return 1;
  return binomialCoeffHelper(n-1, r-1) + binomialCoeffHelper(n-1, r);
}

vector<unsigned int> binomialCoeff(unsigned int n) {
  if (!n) return {1};
  vector<unsigned int> out;
  for (unsigned int i = 0; i < n; ++i) {
    out.push_back(binomialCoeffHelper(n, i));
  }
  out.push_back(1);
  return out;
}

vector<unsigned int> binomialCoeff1(unsigned int n) {
  if (!n) return {1};
  else if (n == 1) return {1, 1};
  vector<unsigned int> ret = {1, 1};
  for (unsigned int j = 2; j <= n; ++j) {
    vector<unsigned int> current = {1};
    for (size_t i = 0; i < ret.size()-1; ++i) {
      current.push_back(ret[i]+ret[i+1]);
    }
    current.push_back(1);
    ret = current;
  }
  return ret;
}

int main() {
  cout << isFactorial(25) << endl;
  cout << largestFactorialFactor(240) << endl;
  cout << multiplyByAdd(-20, 5) << endl;
  vector<unsigned int> out;
  for (auto i : binomialCoeff(5)) {
    cout << i << ", ";
  }
  cout << endl;
  for (auto j : binomialCoeff1(6)) {
    cout << j << ", ";
  }
  cout << endl;
  return 0;
}
