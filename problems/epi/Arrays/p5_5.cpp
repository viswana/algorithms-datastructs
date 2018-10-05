#include <iostream>
#include <vector>

using namespace std;

vector<int> dedup(vector<int> a) {
  for (int i = 0; i < a.size()-1; ) {
    if (a[i] == a[i+1]) {
      a.erase(a.begin()+i+1);
    }
    else i++;
  }
  return a;
}

int dedup2(vector<int>& a) {
  if (a.size() < 2) return a.size();
  int j = 1;
  for (int i = 0; i < a.size()-1; i++) {
    if (a[i] != a[i+1]) {
      if (j < i+1) {
	a[j] = a[i+1];
      }
      j++;
    }
  }
  return j;
}

int filter(vector<int>& a, int key) {
  if (a.size() < 2) return a.size();
  int j = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != key) a[j++] = a[i];
  }
  return j;
}

int filter2(vector<int>& a, int m) {
  if (a.size() < 2) return a.size();
  int keycnt = 1;
  int j = 0;
  int i = 0;
  for(; i < a.size()-1; i++) {
    if (a[i] == a[i+1]) {
      keycnt++;
    }
    else {
      if (keycnt == m) {
	keycnt = (keycnt < 2) ? keycnt : 2;
      }
      while (keycnt) {
	a[j] = a[i];
	j++;
	keycnt--;
      }
      keycnt = 1;
    }
  }
  if(keycnt == m) {
    keycnt = (keycnt < 2) ? keycnt : 2;
  }
  while (keycnt) {
    a[j] = a[i];
    j++;
    keycnt--;
  }
  return j;
}

int main() {
  vector<int> a = {1, 2, 2, 2, 2,5, 5, 6, 7, 7, 7, 7, 7};
  //vector<int> a = {1, 2, 3, 4, 5};
  int x = filter2(a, 5);
  for (auto i : a) {
    cout << i << " ";
  }
  cout << endl;
  cout << "array size is " << x << endl;
  return 0;
}
