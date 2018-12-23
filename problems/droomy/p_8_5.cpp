#include <iostream>
#include <vector>
using namespace std;

void combinationh(int n, int r, int k, vector<int>& col) {
  for (col[k] = col[k-1]+1; col[k] <= n-r+k; col[k]++) {
    if (k < r) combinationh(n, r, k+1, col);
    else {
      for (size_t i = 1; i <= r; i++) {
	cout << col[i] << ", ";
      }
      cout << endl;
    }
  }
}

void combination(int n, int r) {
  if (n < 1 || r < 1) return;
  vector<int> col(r+1, 0);
  combinationh(n, r, 1, col);
}

void allCombinations(int n, int r) {
  if (n < 1 || r < 1) return;
  for(int k = 1; k <= r; ++k) {
    vector<int> col(k+1, 0);
    combinationh(n, k, 1, col); 
  }
}

void rcombinationh(int n, int r, int k, vector<int>& col) {
  for(col[k] = n-r+k; col[k] >= col[k-1]+1; col[k]--) {
    if (k < r) rcombinationh(n, r, k+1, col);
    else {
      for (int i = 1; i <= r; ++i) {
	cout << col[i] << ", ";
      }
      cout << endl;
    }
  }
}

void rcombination(int n, int r) {
  if (n < 1 || r < 1) return;
  vector<int> col(r+1, 0);
  rcombinationh(n, r, 1, col);
}

void icombinations(int n, int r) {
  if (n < 1 || r < 1) return;
  vector<int> col;
  col.push_back(0);
  for(int i = 1; i <=r; ++i) {
    col.push_back(i);
    cout << i << ", ";
  }
  cout << endl;
  for(int k = r; k > 0; ) {
    int colmax = n-r+k;
    if (col[k] < colmax) {
      ++col[k];
      for(int i = k+1; i <= r; ++i) {
	col[i] = col[i-1]+1;
      }
      k = r;
      for(int x = 1; x <=r; ++x) {
	cout << col[x] << ", ";
      }
      cout << endl;
    }
    else {
      --k;
    }
  }
}

int main() {
  icombinations(5, 4);
  return 0;
}
