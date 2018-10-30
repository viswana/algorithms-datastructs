#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int>& a) {
  if (a.size() < 2) return;
  vector<int> s;
  s.push_back(0);
  s.push_back(a.size()-1);
  while (s.size()) {
    int left = s[s.size()-2];
    int right = s[s.size()-1];
    s.pop_back();
    s.pop_back();
    while (left < right) {
      int i = left, j = right;
      int mid = i + (j-i)/2;
      int x = a[mid];
      while (a[i] < x) ++i;
      while (a[j] > x) --j;
      while (i < j-1) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
	++i;
	--j;
	while (a[i] < x) ++i;
	while (a[j] > x) --j;
      }
      if (i <= j) {
	if (i < j) {
	  int t = a[i];
	  a[i] = a[j];
	  a[j] = t;
	}
	++i;
	--j;
      }
      cout << "i is " << i << " j is " << j << endl;
      for (auto y : a) {
	cout << y << ", ";
      }
      cout << endl;
      if (j < mid) {
	s.push_back(i);
	s.push_back(right);
	right = j;
      }
      else {
	s.push_back(left);
	s.push_back(j);
	left = i;
      }
    }    
  }
}

int main() {
  vector<int> a = {20, 35, 18, 8, 14, 41, 3, 39};
  quicksort(a);
  //for (auto i : a) {
  //  cout << i << ", ";
  //}
  //cout << endl;
  return 0;
}
