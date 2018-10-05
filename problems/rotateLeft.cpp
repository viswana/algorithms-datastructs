#include <iostream>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;

void rotateEq(char* const s1, char* const s2, size_t len) {
  if (s1 == NULL || s2 == NULL || len == 0) return;
  char tmp;
  for (size_t i = 0; i < len; i++) {
    tmp = s1[i];
    s1[i] = s2[i];
    s2[i] = tmp;
  }
}

void rotateLeft(char* const s, size_t, size_t);
void rotateRight(char* const s, size_t len, size_t k) {
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

void rotateLeft(char* const s, size_t len, size_t k) {
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

void rotateLeft1(char* const s, size_t len, size_t k) {
  if (!s || len < 2) return;
  if (k == len) return;
  k = k % len;
  size_t count = 0;
  size_t init = 0;
  while ((count < len) && (init < len)) {
    size_t x = init;
    size_t y = (init+k)%len;
    do {
      char tmp = s[x];
      s[x] = s[y];
      s[y] = tmp;
      x = y;
      y = (y+k)%len;
      count++;
    } while (y != init);
    count++;
    init++;
  }
}

void reverse(char* const s, size_t len) {
  if (!s || len < 2) return;
  for (size_t i = 0; i < len/2; i++) {
    char tmp = s[i];
    s[i] = s[len-i-1];
    s[len-i-1] = tmp;
  }
}

void rotateLeft2(char* const s, size_t len, size_t k) {
  if (!s || len < 2) return;
  k = k % len;
  reverse(s, k);
  reverse(s+k, len-k);
  reverse(s, len);
}

int main() {
  size_t iter = 100;
  srand(time(NULL));
  while (iter) {
    size_t len = rand() % 100 + 10;
    char tmp[len];
    char tmp1[len];
    char tmp2[len];
    for (int i = 0; i < len-1; i++) {
      tmp[i] = rand() % 26  + 'a';
      tmp1[i] = tmp[i];
      tmp2[i] = tmp[i];
    }
    tmp[len-1] = '\0';
    tmp1[len-1] = '\0';
    tmp2[len-1] = '\0';
    size_t rot = rand() % len;
    rotateLeft(tmp, strlen(tmp), rot);
    rotateLeft1(tmp1, strlen(tmp1), rot);
    rotateLeft2(tmp2, strlen(tmp2), rot);
    assert(strcmp(tmp, tmp1) == 0);
    assert(strcmp(tmp1, tmp2) == 0);
    iter--;
  }
  return 0;
}

