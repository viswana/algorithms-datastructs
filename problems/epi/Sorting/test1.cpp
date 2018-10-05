#include <iostream>
#include <vector>
using namespace std;

void rotateleft(char* s, size_t len, size_t k) {
  k = k % len;
  if (k == len) return;
  size_t init_idx = 0;
  char temp = s[init_idx];
  for(size_t i = 0; i < len; ) {
    size_t m = init_idx;
    size_t n = (init_idx + k) % len;
    while (n != init_idx) {
      s[m] = s[n];
      m = n;
      n = (n + k) % len;
      i++;
    }
    s[m] = temp;
    init_idx = (init_idx + 1) % len;
    temp = s[init_idx];
    i++;
  }
}

int main() {
  char a[] = "abcdefghij";
  rotateleft(a, 10, 99);
  cout << a << endl;
  return 0;
}
