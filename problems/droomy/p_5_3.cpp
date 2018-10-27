#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& a) {
  if (a.size() < 2) return;
  bool sorted = false;
  for (size_t i = 0; !sorted && i < a.size()-1; ++i) {
    sorted = true;
    for(size_t j = 0; j < a.size()-i-1; ++j) {
      if (a[j] > a[j+1]) {
	sorted = false;
	int t = a[j];
	a[j] = a[j+1];
	a[j+1] = t;
      }
    }
  }
}

void bubbleSort2(vector<int>& a) {
  if (a.size() < 2) return;
  bool sorted = false;
  for (size_t i = a.size()-1; !sorted && i >= 1; --i) {
    bool sorted = true;
    for (size_t j = a.size()-1; j > a.size()-i-1; --j) {
      if (a[j-1] > a[j]) {
	sorted = false;
	int t = a[j-1];
	a[j-1] = a[j];
	a[j] = t;
      }
    }
  }
}

void bubbleSort3(vector<int>& a) {
  if (a.size() < 2) return;
  size_t l = 0, u = a.size()-1;
  size_t cnt = 0;
  bool sorted = false;
  while (!sorted && l < u) {
    sorted = true;
    if (cnt & 1) {
      for (size_t i = u; i > l; --i) {
	if (a[i-1] > a[i]) {
	  int t = a[i-1];
	  a[i-1] = a[i];
	  a[i] = t;
	  sorted = false;
	}
      }
      ++l;
    }
    else {
      for (size_t i = l; i < u; ++i) {
	if (a[i] > a[i+1]) {
	  int t = a[i];
	  a[i] = a[i+1];
	  a[i+1] = t;
	  sorted = false;
	}
      }
      --u;
    }
    ++cnt;
  }
}

int main() {
  vector<int> a = {30, 12, 18, 8, 14, 41, 3, 39};
  bubbleSort3(a);
  for (auto i : a) {
    cout << i << ", ";
  }
  cout << endl;
  return 0;
}
