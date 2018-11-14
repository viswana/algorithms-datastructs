#include <iostream>
#include <vector>
using namespace std;

void insertionsort(vector<int>& a) {
  if (a.size() < 2) return;
  int min = a[0];
  size_t idx = 0;
  for (size_t i = 1; i < a.size(); ++i) {
    if (a[i] < min) {
      min = a[i];
      idx = i;
    }
  }
  int t = a[0];
  a[0] = a[idx];
  a[idx] = t;
  size_t i = 2;
  for (; i < a.size(); ++i) {
    int x = a[i];
    size_t j = i-1;
    for (; a[j] > x; --j) {
      a[j+1] = a[j];
    }
    a[j+1] = x;
  }
}

int main() {
  vector<int> a = {3, 30, 22, 45, 6, 98, 32, 12, 5, 72, 0};
  insertionsort(a);
  for (auto i : a) {
    cout << i << ", ";
  }
  cout << endl;
  return 0;
}
