#include <iostream>
#include <cassert>
#include <vector>
#include "utils.h"
using namespace std;

vector<int> incr(vector<int> a) {
  if (a.size() < 1) return a;
  for (int i = a.size()-1; i > 0; i--) {
    a[i]++;
    if (a[i] == 10) {
      a[i] = 0;
    }
    else {
      break;
    }
  }
  if (a[0] + 1 == 10) {
    a[0] = 1;
    a.push_back(0);
  }
  return a;
}

vector<int> decr(vector<int> a) {
  if (a.size() < 1) return a;
  a.back()--;
  for (int i = a.size()-1; i > 0; i--) {
    if (a[i] == -1) {
      a[i] = 9;
      a[i-1]--;
    }
    else {
      break;
    }
  }
  if (a[0] == 0) {
    a.erase(a.begin());
  }
  return a;
}

int main() {
  vector<int> a = {1,0};
  auto b = decr(a);
  for (auto i : b) {
    cout << i;
  }
  cout << endl;
  return 0;
}
