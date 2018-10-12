#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int multiply(int x, int y) {
  if (x == 0 || y == 0) return 0;
  int a = (x < 0) ? -x : x;
  int b = (y < 0) ? -y : y;
  if (b > a) {
    int t = a;
    a = b;
    b = t;
  }
  int prod = 0;
  while (b > 0) {
    if (b % 2) {
      prod = prod + a;
      --b;
    }
    else {
      a <<= 1;
      b >>= 1;
    }
  }
  if ((x < 0) ^ (y < 0)) prod = -prod;
  return prod;
}

pair<unsigned long, unsigned long> fibPair(unsigned int n) {
  if (!n) return make_pair(0, 1);
  auto tmp = fibPair(n/2);
  auto nsq = tmp.second*tmp.second;
  auto nm1sq = tmp.first*tmp.first;
  auto f2n = nsq + 2*tmp.first*tmp.second;
  auto f2nm1 = nsq + nm1sq;
  if (n % 2) {
    return make_pair(f2nm1, f2n);
  }
  else {
    return make_pair(f2n-f2nm1 ,f2nm1);
  }
}

unsigned long fib(unsigned int n) {
  return fibPair(n).first;
}

unsigned long fib1(unsigned int n) {
  if (!n) return 0;
  unsigned long fn = 1;
  unsigned long fnm1 = 1;
  vector<char> a;
  while (n > 0) {
    a.push_back(n & 1);
    n >>= 1;
  }
  unsigned long f2n;
  unsigned long f2nm1;
  for (int i = a.size()-2; i >= 0; --i) {
    auto nsq = fn*fn;
    auto nm1sq = fnm1*fnm1;
    f2n = nsq + 2*fn*fnm1;
    f2nm1 = nsq + nm1sq;
    if (a[i]) {
      fn = f2n;
      fnm1 = f2nm1;
    }
    else {
      fn = f2nm1;
      fnm1 = f2n - f2nm1;
    }
  }
  return fnm1;
}

int main() {
  cout << multiply(6, 3) << endl;
  cout << fib1(23) << endl;
  return 0;
}
