#include <iostream>
#include <vector>
using namespace std;

int findmax(vector<int>& a) {
  if (a.size() < 1) return -1;
  if (a.size() == 1) return 0;
  int lo = 0, hi = a.size()-1;
  
  while (lo < hi) {
    int mid = lo + (hi-lo)/2;
    //cout << a[mid] << " " << endl;
    if (mid > lo && mid < hi && a[mid] > a[mid-1] && a[mid] > a[mid+1]) return mid;
    else if (mid < hi && a[mid] < a[mid+1]) lo = mid+1;
    //else if (mid >= lo && a[mid] > a[mid+1]) hi = mid-1;
    else hi = mid-1; 
  }
  return lo;
}

int main() {
  vector<int> a = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
  vector<int> b = {1, 2, 3, 4, 5, 6, 7};
  vector<int> c = {6, 5, 4, 3, 2, 1, 0};
  cout << a[findmax(a)] << endl;
  cout << b[findmax(b)] << endl;
  cout << c[findmax(c)] << endl;
  return 0;
}
