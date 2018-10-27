#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void selsort(vector<int>& a) {
  if (!a.size()) return;
  for (size_t i = 0; i < a.size()-1; ++i) {
    int min = a[i];
    size_t pmin = i;
    for (size_t j = i+1; j < a.size(); ++j) {
      if (a[j] < min) {
	min = a[j];
	pmin = j;
      }
    }
    a[pmin] = a[i];
    a[i] = min;
  }
}

int minmax(const vector<int>& t, size_t l, size_t u, pair<size_t, size_t>& out) {
  if (t.size() < 2 || u - l < 1) return -1;
  int gmin, gmax;
  size_t i = l+1;
  size_t minidx, maxidx;
  if (t[i-1] < t[i]) {
    gmin = t[i-1];
    gmax = t[i];
    minidx = i-1;
    maxidx = i;
  }
  else {
    gmin = t[i];
    gmax = t[i-1];
    minidx = i;
    maxidx = i-1;
  }
  i += 2;
  for (; i <= u; i += 2) {
    int lmin, lmax;
    size_t lminidx, lmaxidx;
    if (t[i-1] < t[i]) {
      lmin = t[i-1];
      lmax = t[i];
      lminidx = i-1;
      lmaxidx= i;
    }
    else {
      lmin = t[i];
      lmax = t[i-1];
      lminidx = i;
      lmaxidx = i-1;
    }
    if (lmin < gmin) {
      gmin = lmin;
      minidx = lminidx;
    }
    if (lmax > gmax) {
      gmax = lmax;
      maxidx = lmaxidx;
    }
  }
  if (!((u-l) & 1)) {
    if (t[u] < gmin) {
      gmin = t[u];
      minidx = u;
    }
    if (t[u] > gmax) {
      gmax = t[u];
      maxidx = u;
    }
  }
  out = make_pair(minidx, maxidx);
  return 0;
}

void selsort2(vector<int>& a) {
  size_t l = 0, u = a.size()-1;
  while (l < u) {
    pair<size_t, size_t> out;
    minmax(a, l, u, out);
    if (l == out.second && u == out.first) {
      int t = a[l];
      a[l] = a[out.first];
      a[out.first] = t;
    }
    else if (l != out.first && u != out.second) {
      if (l == out.second) {
	int t = a[u];
	a[u] = a[out.second];
	a[out.second] = t;
	t = a[l];
	a[l] = a[out.first];
	a[out.first] = t;
      }
      else {
	int t = a[l];
	a[l] = a[out.first];
	a[out.first] = t;
	t = a[u];
	a[u] = a[out.second];
	a[out.second] = t;
      }
    }
    ++l;
    --u;
  }
}

size_t selsortDedup(vector<int>& a) {
  if (a.size() < 2) return a.size();
  size_t i = 0, j = 0;
  for (; i < a.size(); ++i) {
    int min = a[i];
    size_t pmin = i;
    for (size_t k = i+1; k < a.size(); ++k) {
      if (a[k] < min) {
	min = a[k];
	pmin = k;
      }
    }
    a[pmin] = a[i];
    a[j] = min;
    if (!j) ++j;
    else {
      if (a[j] != a[j-1]) ++j;
    }
  }
  return j;
}

bool isNonDescending(const vector<int>& a) {
  if (a.size() < 2) return true;
  for (size_t i = 1; i < a.size(); ++i) {
    if (a[i-1] > a[i]) return false;
  }
  return true;
}

int main() {
  vector<int> a = {20, 20, 35, 18, 8, 14, 41, 41, 3, 39};
  cout << selsortDedup(a) << endl;
  for (auto i : a) {
    cout << i << ", ";
  }
  cout << endl;
  return 0;
}
