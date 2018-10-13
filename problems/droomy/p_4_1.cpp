#include <iostream>
#include <vector>
using namespace std;

void reverse(int* a, size_t len) {
  if (!a || !len) return;
  size_t i = 0, j = len-1;
  while (i < j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
    ++i;
    --j;
  }
}

void rotateleft(int* a, size_t len, size_t k) {
  if (!a || !len) return;
  k = k % len;
  reverse(a, k);
  reverse(a+k, len-k);
  reverse(a, len);
}

void rotateleft1(int* a, size_t len, size_t k) {
  if (!a || !len) return;
  k = k % len;
  size_t sidx = 0;
  size_t cnt = 0;
  while (cnt < len) {
    int tmp = a[sidx];
    size_t i = sidx;
    size_t j = (i + k) % len;
    while(j != sidx) {
      a[i] = a[j];
      i = (i + k) % len;
      j = (i + k) % len;
      ++cnt;
    }
    a[i] = tmp;
    ++cnt;
    ++sidx;
  }
}

void oddeven(int* a, size_t len) {
  if (!a || !len || len == 1) return;
  size_t termcnt = (len & 1) ? len - 1 : len;
  size_t sidx = 0;
  size_t tmpidx = 0;
  int tmpdata = a[tmpidx];
  size_t firstevenidx = 0;
  size_t lastoddidx = (len & 1) ? len - 2 : len - 1;
  size_t firstevendestidx = len/2;
  size_t lastodddestidx = len/2 - 1;
  while (termcnt > 0) {
    do {
      size_t destidx;
      if (tmpidx & 1) {
	destidx = lastodddestidx - (lastoddidx - tmpidx)/2;
      }
      else {
	destidx = firstevendestidx + (tmpidx - firstevenidx)/2;
      }
      int t = tmpdata;
      tmpdata = a[destidx];
      a[destidx] = t;
      tmpidx = destidx;
      --termcnt;
    } while (tmpidx != sidx);
    sidx += 2;
    tmpidx = sidx;
    tmpdata = a[tmpidx];
  }
}

int main() {
  int a[] = {1, 2, 3, 4, 5, 6};
  reverse(a, sizeof(a)/sizeof(int));
  for (auto i : a) {
    cout << i << ", ";
  }
  cout << endl;
  rotateleft1(a, sizeof(a)/sizeof(int), 2);
  for (auto i : a) {
    cout << i << ", ";
  }
  cout << endl;
  int b[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  oddeven(b, sizeof(b)/sizeof(int));
  for (auto i : b) {
    cout << i << ", ";
  }
  cout << endl;
  return 0;
}
