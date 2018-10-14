#include <iostream>
#include <utility>
using namespace std;

int mymin(int* a, size_t len) {
  if (!a || !len) return -1;
  int min = a[0];
  for (size_t i = 1; i < len; ++i) {
    if (a[i] < min) min = a[i];
  }
  return min;
}

unsigned int numMax(int* a, size_t len) {
  if (!a || !len) return 0;
  int max = a[0];
  unsigned int nummax = 1;
  for (size_t i = 1; i < len; ++i) {
    if (a[i] > max) {
      max = a[i];
      nummax = 1;
    }
    else if (a[i] == max) nummax++;
  }
  return nummax;
}

typedef struct _loc {
  int x;
  unsigned int num;
  size_t firstidx;
  size_t lastidx;
} loc, *ploc;

int minmax(int* a, size_t len, pair<int, int>& ret) {
  if (!a || !len) return -1;
  if (len == 1) {
    ret =  make_pair(a[0], a[0]);
    return 0;
  }
  int globmin;
  int globmax;
  if (a[0] < a[1]) {
    globmin = a[0];
    globmax = a[1];
  }
  else {
    globmin = a[1];
    globmax = a[0];
  }
  for (size_t i = 3; i < len; i += 2) {
    int localmin;
    int localmax;
    if (a[i-1] < a[i]) {
      localmin = a[i-1];
      localmax = a[i];
    }
    else {
      localmin = a[i];
      localmax = a[i-1];
    }
    if (localmin < globmin) globmin = localmin;
    if (localmax > globmax) globmax = localmax;
  }
  if (len & 1) {
    if (a[len-1] < globmin) globmin = a[len-1];
    if (a[len-1] > globmax) globmax = a[len-1];
  }
  ret = make_pair(globmin, globmax);
  return 0;
}

int main() {
  int a[] = {13, 20, 25, 44, 50, 57, 7};
  pair<int, int> ret;
  minmax(a, sizeof(a)/sizeof(int), ret);
  cout << ret.first << ", " << ret.second << endl;
  return 0;
}
