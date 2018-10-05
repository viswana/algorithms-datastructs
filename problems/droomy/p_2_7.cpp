#include <iostream>
#include <vector>
using namespace std;

unsigned int numDigits(unsigned int n) {
  int cnt = 0;
  while (n) {
    n = n/10;
    cnt++;
  }
  return cnt;
}

unsigned int sumDigits(unsigned int n) {
  int sum = 0;
  while (n) {
    sum += n % 10;
    n = n/10;
  }
  return sum;
}

unsigned int makeInt(vector<unsigned int> n) {
  unsigned int sum = 0;
  for (size_t i = 0; i < n.size(); ++i) {
    sum = sum*10 + n[i];
  }
  return sum;
}

int main() {
  cout << sumDigits(makeInt({2, 7, 4, 9, 3})) << endl;
  return 0;
}
