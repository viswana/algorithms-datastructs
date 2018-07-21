#include <iostream>
#include <cstring>
using namespace std;

void rotateEq(char* s1, char* s2, size_t len) {
  if (s1 == NULL || s2 == NULL || len == 0) return;
  char tmp;
  for (size_t i = 0; i < len; i++) {
    tmp = s1[i];
    s1[i] = s2[i];
    s2[i] = tmp;
  }
}

void rotateLeft(char* s, size_t, size_t);
void rotateRight(char* s, size_t len, size_t k) {
  if (k == 0) return;
  if (k >= len) return rotateRight(s, len, k%len);
  if (k*2 == len) return rotateEq(s, s+k, k);
  else if (k*2 < len) {
    rotateEq(s, s+len-k, k);
    rotateRight(s+k, len-k, k);
  }
  else {
    rotateEq(s, s+k, len-k);
    rotateLeft(s, k, len-k);
  }
}

void rotateLeft(char* s, size_t len, size_t k) {
  if (k == 0) return;
  if (k >= len) return rotateLeft(s, len, k%len);
  if (k*2 == len) return rotateEq(s, s+k, k);
  else if (k*2 < len) {
    rotateEq(s, s+len-k, k);
    rotateLeft(s, len-k, k);
  }
  else {
    rotateEq(s, s+k, len-k);
    rotateRight(s+len-k, k, len-k);
  }
}

int main() {
  //char tmp[] = "abcdefghijkl";
  char tmp[] = "a";
  rotateRight(tmp, strlen(tmp), 12);
  cout << tmp << endl;
  return 0;
}

