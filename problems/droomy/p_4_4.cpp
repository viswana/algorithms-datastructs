#include <iostream>
using namespace std;

size_t dedup(int* a, size_t len) {
  if (!a || len < 2) return len;
  size_t j = 1;
  size_t i = 1;
  for (; a[i-1] != a[i] && i < len; ++i);
  j = i;
  ++i;
  for (; i < len; ++i) {
    if (a[i-1] != a[i]) {
      a[j] = a[i];
      ++j;
    }
  }
  return j;
}

size_t filterdup(int* a, size_t len) {
  if (!a || len < 2) return len;
  size_t j = 0;
  size_t i = 1;
  for (; a[i-1] != a[i] && i < len; ++i, ++j);
  if (j == len-1) return i;
  i += 2;
  for (; i < len;) {
    if (a[i-1] != a[i]) {
      a[j] = a[i-1];
      ++j;
      ++i;
    }
    else {
      i += 2;
    }
  }
  if (a[len-1] != a[len-2]) {
    a[j] = a[len-1];
    ++j;
  }
  return j;
}

int main() {
  int a[] = {0, 1, 2, 2, 2, 3, 4, 5, 6, 6, 7, 8, 9, 9, 10};
  auto x = dedup(a, sizeof(a)/sizeof(int));
  for (size_t i = 0; i < x; ++i) {
    cout << a[i] << ", ";
  }
  cout << endl;
  cout << "New size is " << x << endl;
  int b[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 8, 9, 10, 11, 12, 14};
  x = filterdup(b, sizeof(b)/sizeof(int));
  for (size_t i = 0; i < x; ++i) {
    cout << b[i] << ", ";
  }
  cout << endl;
  cout << "New size is " << x << endl;
  return 0;
}
