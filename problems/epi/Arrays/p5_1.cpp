#include <iostream>
#include <cassert>
#include "utils.h"
using namespace std;

void DutchFlagPartition(int* a, size_t len, int x) {
  if (!a || len < 2) return;
  size_t lt = 0, i = 0, gt = len-1;
  while (i <= gt) {
    if (a[i] < x) swp(a[lt++], a[i++]);
    else if (a[i] > x) swp(a[gt--], a[i]);
    else i++;
  }
}

void bucketize3(int* a, size_t len, int x, int y, int z) {
  if (!a || len < 4) return;
  size_t xi = 0, yi = 0, zi = len-1;
  while (yi <= zi) {
    if (a[yi] == x) swp(a[xi++], a[yi++]);
    else if (a[yi] == z) swp(a[yi], a[zi--]);
    else yi++;
  }
}

int main() {
  int a[] = {3, 5, 1, 2, 5, 6, 5, 7};
  DutchFlagPartition(a, sizeof(a)/sizeof(int), 5);
  for (int i = 0; i < sizeof(a)/sizeof(int); i++)
    cout << a[i] << " ";
  cout << endl;
  int b[] = {3, 4, 4, 4, 5, 5, 4, 3, 4, 3};
  bucketize3(b, sizeof(b)/sizeof(int), 5, 4, 3);
  for (int i = 0; i < sizeof(b)/sizeof(int); i++)
    cout << b[i] << " ";
  cout << endl;
  return 0;
}
