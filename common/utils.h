#ifndef __UTILS_H__
#define __UTILS_H__
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <functional>
using namespace std;

template <typename T>
inline void swp(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
inline const T& min(const T& a, const T& b) {
  if (a < b) return a;
  else return b;
}

template <typename T>
inline const T& max(const T& a, const T& b) {
  if (a > b) return a;
  else return b;
}

template <typename T>
int cmp(const T& lhs, const T& rhs) {
  if (lhs == rhs) return 0;
  else if (lhs < rhs) return -1;
  else return 1;
}

template <typename T>
bool lt(const T& lhs, const T& rhs) {
  return cmp<T>(lhs, rhs) == -1;
}

template <typename T>
bool le(const T& lhs, const T& rhs) {
  return cmp<T>(lhs, rhs) != 1;
}

template <typename T>
bool gt(const T& lhs, const T& rhs) {
  return cmp<T>(lhs, rhs) == 1;
}

template <typename T>
bool ge(const T& lhs, const T& rhs) {
  return cmp<T>(lhs, rhs) != -1;
}

template <typename T>
bool eq(const T& lhs, const T& rhs) {
  return cmp<T>(lhs, rhs) == 0;
}

template <typename T>
bool neq(const T& lhs, const T& rhs) {
  return cmp<T>(lhs, rhs) != 0;
}

int randint(size_t l, size_t u) {
  if (u < l) return -1;
  srand(time(NULL));
  return l + rand() % (u-l+1);
}

template <typename T>
void rshuffle(T * const a, size_t len) {
  if (!a || len < 2) return;
  for (size_t i = 0; i < len; i++) {
    size_t idx = randint(i, len-1);
    swp<T>(a[i], a[idx]);
  }
}

template <typename T>
int qselect(T* a, size_t len, size_t i, size_t& q) {
  if (!a || len < 1 || i >= len) return -1;
  if (len == 1) {
    q = a[0];
    return 0;
  }
  while (true) {
    size_t m = 0;
    T pivot = a[0];
    for (size_t i = 1; i < len; i++) {
      if (a[i] < pivot) {
	m++;
	swp(a[m], a[i]);
      }
    }
    swp(a[0], a[m]);
    if (i == m) {
      q = a[m];
      return 0;
    }
    else if (i < m) {
      len = m;
    }
    else {
      a = a+m+1;
      len = len-m-1;
      i = i-m-1;
    }
  }
}

template <typename T>
class btnode {
public:
  T data;
  btnode* left;
  btnode* right;
  btnode* parent;
  btnode(T item) : data(item), left(NULL), right(NULL), parent(NULL) {};
};

template <typename T>
btnode<T>* makeTree(vector<T>& preorder, vector<T>& inorder, unordered_map<T, size_t>& inIdxMap, int prelo, int prehi, int inlo, int inhi) {
  if (preorder.empty() || inorder.empty() || inIdxMap.empty()) return NULL;
  if (inlo > inhi || prelo > prehi) return NULL;
  T rootkey = preorder[prelo];
  btnode<T>* root = new btnode<T>(rootkey);
  int leftTreesz = inIdxMap[rootkey] - inlo;
  int rightTreesz = inhi - inIdxMap[rootkey];
  root->left = makeTree(preorder, inorder, inIdxMap,
			prelo+1, prelo + leftTreesz,
			inlo, inIdxMap[rootkey]-1);
  root->right = makeTree(preorder, inorder, inIdxMap,
			 prehi - rightTreesz + 1, prehi,
			 inIdxMap[rootkey] + 1, inhi);
  if (root->left) root->left->parent = root;
  if (root->right) root->right->parent = root;
  return root;
}

template<typename T>
btnode<T>* deltree(btnode<T>* t) {
  if (!t) return t;
  if (t->left) t->left = deltree(t->left);
  else if (t->right) t->right = deltree(t->right);
  delete(t);
  t = NULL;
  return t;
}

template <typename T, typename F>
  int bsearch(vector<T>& a, T tgt, F pred, int& rank) {
  if (!a.size()) return -1;
  int lo = 0, hi = a.size()-1;
  while (lo <= hi) {
    size_t mid = lo + (hi-lo)/2;
    int cmp = pred(tgt, a[mid]);
    if (cmp == 0) {
      rank = mid;
      return 0;
    }
    else if (cmp < 0) {
      hi = mid-1;
    }
    else lo = mid+1;
  }
  rank = lo;
  return 1;
}

#endif
