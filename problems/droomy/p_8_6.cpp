#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

void permutationh(int n, int r, int k, vector<int>& col, vector<bool>& available) {
  for (int i = 1; i <= n; ++i) {
    if (available[i]) {
      available[i] = false;
      col[k] = i;
      if (k < r-1) {
	permutationh(n, r, k+1, col, available);
      }
      else {
	for (int j = 0; j < r; ++j) {
	  cout << col[j] << ", ";
	}
	cout << endl;
      }
      available[i] = true;
    }
  }
}

void permutations(int n, int r) {
  if (n < 1 || r < 1 || r > n) return;
  vector<int> col(r, 1);
  vector<bool> avail(n+1, true);
  permutationh(n, r, 0, col, avail);
}

void permutationh1(int n, int r, int k, vector<int>& col) {
  if (k == n-1 || k == r-1) {
    for (int x = 0; x < r; ++x) {
	cout << col[x] << ", ";
      }
      cout << endl;
  }
  else {
    permutationh1(n, r, k+1, col);
  }
  int temp = col[k];
  for(int j = k+1; j < n; ++j) {
    col[k] = col[j];
    col[j] = temp;
    if (k < r-1) {
      permutationh1(n, r, k+1, col);
    }
    else {
      for (int x = 0; x < r; ++x) {
	cout << col[x] << ", ";
      }
      cout << endl;
    }
    col[j] = col[k];
    col[k] = temp;
  }
}

void permutations1(int n, int r) {
  if (n < 1 || r < 1 || r > n) return;
  vector<int> col;
  for (int i = 0; i < n; ++i) {
    col.push_back(i+1);
  }
  permutationh1(n, r, 0, col);
}

void allPermutations(int n, deque<vector<int> >& out) {
  if (n < 1) return;
  if (n == 1) {
    out.push_back(vector<int>(1, 1));
    return;
  }
  allPermutations(n-1, out);
  size_t cnt = out.size();
  while (cnt) {
    vector<int> next = out.front();
    out.pop_front();
    for(size_t x = 0; x <= next.size(); ++x) {
      vector<int> append;
      for(size_t i = 0; i < x; ++i) {
	append.push_back(next[i]);
      }
      append.push_back(n);
      for(size_t i = x; i < next.size(); ++i) {
	append.push_back(next[i]);
      }
      out.push_back(append);
    }
    --cnt;
  }
}

void allPermutations2h(int* a, int n, int pos) {
  if (pos == n) return;
  if (a[pos] > a[pos-1]) allPermutations2h(a, n, pos+1);
  else {
    int suc = pos-1;
    for (int i = pos-2; i >= 0; --i) {
      if (a[i] < a[suc] && a[i] > a[pos]) suc = i;
    }
    int temp = a[suc];
    a[suc] = a[pos];
    a[pos] = temp;
    for (int i = pos-1, j = 0; i > j; --i, ++j) {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
    for(int i = n-1; i >= 0; --i) {
      cout << a[i] << ", ";
    }
    cout << endl;
    allPermutations2h(a, n, 1);
  }
}

void allPermutations2(int n) {
  if (n < 2 || n > 10) return;
  int a[n];
  for(int i = 0; i < n; ++i) {
    a[i] = n-i-1;
    cout << i << ", ";
  }
  cout << endl;
  allPermutations2h(a, n, 1);
}

int main() {
  //permutations1(3, 3);
  /*
  deque<vector<int> > p;
  allPermutations(4, p);
  for(auto i : p) {
    for (auto j : i) {
      cout << j << ", ";
    }
    cout << endl;
  }
  */
  allPermutations2(5);
}
