#include <iostream>
#include <algorithm>
using namespace std;

void MarkHistogram(unsigned int* a, size_t len) {
  if (!a || !len) return;
  unsigned int hist[10] = {0};
  double sum = 0;
  for (size_t i = 0; i < len; ++i) {
    ++hist[(a[i]-1)/10];
    sum += a[i];
  }
  for (size_t i = 0; i < 10; ++i) {
    cout << hist[i] << ", ";
  }
  cout << endl;
  sort(a, a+len);
  cout.precision(4);
  cout << "Mean is " << sum/len << endl;
  cout << "Median is " << ((len & 1) ? a[len/2] : (double)(a[(len-1)/2] + a[len/2])/2) << endl;
}

int main() {
  unsigned int a[] = {13, 25, 44, 57, 99, 100, 20, 67, 50};
  MarkHistogram(a, sizeof(a)/sizeof(unsigned int));
  return 0;
}
