#include <iostream>
using namespace std;

int findKthSmallest(int* a, int len, int k, int& out) {
  if (!a || !len || k > len-1) return -1;
  int l = 0, u = len-1;
  while (l < u) {
    int i = l, j = u;
    int x = a[k];
    while (i <= k && j >=k) {
      while (a[i] < k) ++i;
      while (a[j] > k) --j;
      int t = a[i];
      a[i] = a[j];
      a[j] = t;
      ++i;
      --j;
    }
    if (i > k) u = j;
    if (j < k) l = i;
  }
  out = a[k];
  return 0;
}

int main() {
  int a[] = {3, 4, 1, 2, 23, 5, 9, 5, 10, 6};
  int out;
  int ret = findKthSmallest(a, sizeof(a)/sizeof(int), 9, out);
  if (!ret) {
    for (auto i : a) {
      cout << i << ", ";
    }
    cout << endl;
    cout << "kth smallest is : " << out << endl;
  }
  else {
    cout << "Somethings wrong" << endl;
  }
  return 0;
}
