#include <iostream>
#include <vector>
using namespace std;

bool binsearch(const vector<int>& a, const int x, size_t& rank) {
  if (!a.size()) return false;
  size_t l = 0, u = a.size()-1;
  while (l < u) {
    size_t m = l + (u-l)/2;
    if (x > a[m]) {
      l = m+1;
    }
    else {
      u = m;
    }
  }
  rank = l;
  return (x == a[l]);
}

bool binsearch1(const vector<int>& a, const int x, size_t& rank) {
  if (!a.size()) return false;
  size_t l = 0, u = a.size()-1;
  while (l < u) {
    size_t m = l + (u-l)/2;
    if (x == a[m]) {
      rank = m;
      return true;
    }
    else if (x > a[m]) {
      l = m+1;
    }
    else {
      u = m-1;
    }
  }
  rank = (x > a[l]) ? l+1 : l;
  return (x == a[l]);
}

bool binsearch2(const vector<int>& a, const int x, size_t& rank) {
  if (!a.size()) return false;
  size_t l = 0, u = a.size()-1;
  while (l < u) {
    size_t m = l + (u-l+1)/2;
    if (x < a[m]) {
      u = m-1;
    }
    else {
      l = m;
    }
  }
  rank = (x > a[l]) ? l+1 : l;
  return (x == a[l]);
}

int main() {
  vector<int> a = {42, 44, 45, 49, 57, 63, 70};
  size_t rank;
  
  cout << ((binsearch2(a, 50, rank)) ? "Found 57" : "Couldn't find 57") << " Rank is " << rank << endl;
  return 0;
}
