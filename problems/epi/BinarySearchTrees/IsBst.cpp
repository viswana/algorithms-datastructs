#include <iostream>
#include <unordered_map>
#include <vector>
#include "utils.h"
#include <queue>
#include <limits>
using namespace std;

template <typename T>
bool isBst(btnode<T>* t) {
  if (!t) return true;
  if (!t->left && !t->right) return true;
  else if (t->left && !t->right) return (t->data >= t->left->data) && isBst(t->left);
  else if (!t->left && t->right) return (t->data <= t->right->data) && isBst(t->right);
  else return (t->data >= t->left->data) && (t->data <= t->right->data) && isBst(t->left) && isBst(t->right);
}

template <typename T>
class qitem {
public:
  btnode<T>* t;
  T low;
  T high;
};

template <typename T>
bool isBst1(btnode<T>* t, T low, T high) {
  if (!t) return true;
  queue<qitem<T>> q;
  q.push({t, low, high});
  while (!q.empty()) {
    qitem<T> tmp = q.front();
    q.pop();
    if (tmp.t->data < tmp.low || tmp.t->data > tmp.high) {
      cout << tmp.t->data << " " << tmp.low << " " << tmp.high << endl;
      return false;
    }
    if (tmp.t->left) {
      q.push({tmp.t->left, tmp.low, tmp.t->data});
    }
    if (tmp.t->right) {
      q.push({tmp.t->right, tmp.t->data, tmp.high});
    }
  }
  return true;
}

template <typename T>
bool isBst2(btnode<T>* t, T* prev) {
  if (!t) return true;
  if (isBst2(t->left, prev)) {
    if (t->data < *prev) return false;
    *prev = t->data;
    cout << *prev << endl;
    return isBst2(t->right, prev);
  }
  return false;
}
  

int main() {
  vector<int> inorder = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> preorder = {5, 2, 1, 3, 4, 7, 6, 8, 9};
  //vector<int> inorder = {1, 3, 2, 4, 5, 6, 7, 8, 9};
  //vector<int> preorder = {5, 3, 1, 2, 4, 7, 6, 8, 9};
  unordered_map<int, size_t> inIdxMap;
  for (size_t i = 0; i < inorder.size(); i++)
    inIdxMap.insert({inorder[i], i});
  btnode<int>* t = makeTree(preorder, inorder, inIdxMap, 0, preorder.size()-1,
			    0, inorder.size()-1);
  cout << isBst1(t, numeric_limits<int>::min(), numeric_limits<int>::max()) << endl;
  //cout << isBst(t) << endl;
  int prev = numeric_limits<int>::min();
  cout << isBst2(t, &prev) << endl;
  deltree(t);
  return 0;
}
