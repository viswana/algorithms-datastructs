#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void samplegenh(int n, int r, int k, vector<int>& col) {
  col[k-1] = 0;
  while (col[k-1] < n) {
    col[k-1]++;
    if (k < r) 
      samplegenh(n, r, k+1, col);
    else {
      for (auto i : col)
	cout << i << ", ";
      cout << endl;
    }
  }
}

void samplegenh1(int n, int r, int k, vector<int>& col) {
  for(col[k-1] = 1; col[k-1] <= n; col[k-1]++) {
    if (k < r) samplegenh1(n, r, k+1, col);
    else {
      for (auto i : col)
	cout << i << ", ";
      cout << endl;
    }
  }
}

void samplegen(int n, int r) {
  if (n < 1 || r < 1) return;
  vector<int> col(r, 0);
  samplegenh1(n, r, 1, col);
}

void rsamplegenh(int n, int r, int k, vector<int>& col) {
  for (col[k-1] = n; col[k-1] > 0; col[k-1]--) {
    if (k < r) {
      rsamplegenh(n, r, k+1, col);
    }
    else {
      for (size_t j = 0; j < r; ++j) {
	cout << col[j] << ", ";
      }
      cout << endl;
    }
  }
}

void rsamplegen(int n, int r) {
  if (n < 1 || r < 1) return;
  vector<int> col(r, n);
  rsamplegenh(n, r, 1, col);
}

void isamplegen(int n, int r) {
  if (n < 1 || r < 1) return;
  //Find n raised to r
  size_t t = r;
  size_t i = 1;
  while (t) {
    i *= n;
    t--;
  }
  vector<int> col(r, 1);
  for (size_t j = 0; j < i; ++j) {
    //convert j base 10 to base n
    size_t d = j;
    size_t k = r-1;
    while (d >= n) {
      col[k] = (d % n) + 1;
      --k;
      d = d/n;
    }
    col[k] = d + 1;
    for (size_t x = 0; x < r; x++) {
      cout << col[x] << ", ";
    }
    cout << endl;
  }
}

void isamplegen2(int n, int r) {
  if (n < 1 || r < 1) return;
  vector<int> col(r, 1);
  for (int x = 0; x < r; ++x) {
	cout << col[x] << ", ";
  }
  cout << endl;
  for (int i = r-1; i >=0; ) {
    if (col[i] < n) {
      col[i]++;
      for (int j = i+1; j < r; ++j) {
	col[j] = 1;
      }
      for (int x = 0; x < r; ++x) {
	cout << col[x] << ", ";
      }
      cout << endl;
      i = r-1;
    }
    else {
      --i;
    }
  }
}

void nextAndPrevPerm(int n, int r, const vector<int>& cur) {
  if (n < 1 || r < 1 || r != cur.size()) return;
  vector<int> next(cur);
  vector<int> prev(cur);
  int i = r-1;
  for (; i >= 0 && next[i] == n; next[i] = 1, --i);
  if (i >= 0) next[i]++;
  for(int i = 0; i < r; ++i) {
    cout << next[i] << ", ";
  }
  cout << endl;
  i = r-1;
  for(; i >=0 && prev[i] == 1; prev[i] = 5, --i);
  if (i >= 0) prev[i]--;
   for(int i = 0; i < r; ++i) {
    cout << prev[i] << ", ";
  }
  cout << endl;
}

unsigned int greycodegen(unsigned int cur) {
  if (!cur) return 0;
  unsigned int prevgc = greycodegen(cur-1);
  return prevgc ^ (cur & ~(cur-1));
}

int main() {
  //isamplegen2(5, 3);
  nextAndPrevPerm(5, 3, {5, 5, 5});
  cout << greycodegen(7) << endl;
  return 0;
}
