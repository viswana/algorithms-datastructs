#include <iostream>
#include <vector>
using namespace std;

void twoWayMerge(vector<int>& a, vector<int>& b, vector<int>& c) {
  size_t i = 0, j = 0;
  while (i < a.size() && j < b.size()) {
    if (a[i] <= b[j]) {
      c.push_back(a[i]);
      ++i;
    }
    else {
      c.push_back(b[j]);
      ++j;
    }
  }
  if (i < a.size()) {
    while(i < a.size()) {
      c.push_back(a[i]);
      ++i;
    }
  }
  else {
    while (j < b.size()) {
      c.push_back(b[j]);
      ++j;
    }
  }
}

int main() {
  vector<int> a = {15, 18, 42, 51};
  vector<int> b = {8, 11, 16, 17, 44, 58, 71, 74};
  vector<int> c;
  twoWayMerge(a, b, c);
  for (auto i : c) {
    cout << i << ", ";
  }
  cout << endl;
  return 0;
}
