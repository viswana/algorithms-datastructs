#include <iostream>
#include "utils.h"
#include <vector>
#include <unordered_map>
using namespace std;

template <typename T>
void FindKLargest(btnode<T>* t, int k, vector<T>& out) {
  if (!t || k < 1) return;
  FindKLargest(t->right, k, out);
  if (out.size() < k) {
    out.push_back(t->data);
    FindKLargest(t->left, k, out);
  }
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
  vector<int> out;
  FindKLargest(t, 3, out);
  for (auto i : out) {
    cout << i << " ";
  }
  cout << endl;
  deltree(t);
  return 0;
}
