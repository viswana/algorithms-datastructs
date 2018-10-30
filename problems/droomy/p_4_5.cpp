#include <iostream>
#include <utility>
using namespace std;

/** 
Returns -1 if all elements are greater than x
Returns len-1 if all elements are <= x
Retursn -2 on wrong inputs
*/

int partition(int* a, int len, int x) {
  if (!a || len < 1) return -2;
  int i = 0;
  int j = len-1;
  while (a[i] <= x && i < j) ++i;
  while (a[j] > x && i < j) --j;
  if (a[j] > x) --j;
  while (i < j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
    ++i;
    --j;
    while (a[i] <= x) ++i;
    while (a[j] > x) --j;
  }
  return j;
}

int partition2(int* a, int len, int x) {
  if (!a || len < 1) return -2;
  int i = 0;
  int j = len-1;
  while (i < j) {
    if (a[i] <= x) ++i;
    else if (a[j] > x) --j;
    else {
      int t = a[i];
      a[i] = a[j];
      a[j] = t;
      ++i;
      --j;
    }
  }
  if (a[j] > x) --j;
  return j;
}

int partition3(int* a, int len, int x) {
  if (!a || len < 1) return -2;
  int m = 0, i = 0;
  for (; i < len && a[i] <= x; ++i, ++m);
  if (i == len) return m-1;
  while (i < len) {
    if (a[i] > x) ++i;
    else {
      int t = a[m];
      a[m] = a[i];
      a[i] = t;
      ++i;
      ++m;
    }
  }
  return m-1;
}

int rangePartition(int* a, int len, pair<int, int> range, pair<int, int>& out) {
  if (!a || len < 1)  return -1;
  int i = 0, k = 0, j = len-1;
  while (k < j) {
    if (a[k] < range.first) {
      int t = a[i];
      a[i] = a[k];
      a[k] = t;
      ++i;
      ++k;
    }
    else if (a[k] > range.second) {
      int t = a[j];
      a[j] = a[k];
      a[k] = t;
      --j;
    }
    else {
      ++k;
    }
  }
  if (a[k] < range.first) {
    int t = a[i];
    a[i] = a[k];
    a[k] = t;
    ++i;
    ++k;
  }
  else if (a[k] > range.second) {
    --j;
  }
  out = make_pair(i, j);
  return 0;
}

int rangePartition1(int* a, int len, pair<int, int> range, pair<int, int>& out) {
  if (!a || len < 1) return -1;
  int i = 0, k = 0, j = len-1;
  for(; a[i] < range.first && k < j; ++i, ++k);
  for(; a[j] > range.second && k < j; --j);
  if (a[j] > range.second) --j;
  while (k <= j) {
    if (a[k] < range.first) {
      int t = a[i];
      a[i] = a[k];
      a[k] = t;
      ++i;
      ++k;
    }
    else if (a[k] > range.second) {
      int t = a[j];
      a[j] = a[k];
      a[k] = t;
      --j;
    }
    else {
      ++k;
    }
  }
  out = make_pair(i, j);
  return 0;
}

typedef enum color {
  red, white, blue
} color, *pcolor;

int dutchFlagPartition(pcolor a, size_t len) {
  if (!a || len < 3) return -1;
  int i = 0, k = 0, j = len-1;
  for (; a[i] == red && k < j; ++i, ++k);
  for (; a[j] == blue && k < j; --j);
  if (a[j] == blue) --j;
  while (k <= j) {
    if (a[k] == red) {
      color t = a[i];
      a[i] = a[k];
      a[k] = t;
      ++i;
      ++k;
    }
    else if (a[k] == blue) {
      color t = a[j];
      a[j] = a[k];
      a[k] = t;
      --j;
    }
    else {
      ++k;
    }
  }
  cout << i << ", " << j << ", " << k << endl;
  return 0;
}

int main() {
  int a[] = {15, 11, 9, 6, 5, 3, 4, 7, 9, 13, 25};
  int b[] = {3, 2, 5, 9, 18, 21, 4, 6, 11};
  int c[] = {11, 20, 12, 13, 14, 12, 33};
  int d[] = {0, 1, 3, 4, 2, 1, 0, -1};
  pair<int, int> out;
  rangePartition1(d, sizeof(d)/sizeof(int), make_pair(5, 10), out);
  cout << "Extracted range is " << out.first << ", " << out.second << endl;
  for (auto i : d) {
    cout << i << ", ";
  }
  cout << endl;
  int m = partition3(a, sizeof(a)/sizeof(int), 9);
  for (auto i : a) {
    cout << i << ",  ";
  }
  cout << endl;
  cout << m << endl;
  color x[] = {red, white, red, blue, white, red, red, blue, blue, white};
  color y[] = {red, red, white, white, white, white, blue};
  dutchFlagPartition(y, sizeof(y)/sizeof(color));
  for (auto i : y) {
    cout << i << ", ";
  }
  cout << endl;
  return 0;
}
