#include <iostream>
#include "utils.h"
#include <vector>
#include <limits>
#include <queue>
using namespace std;

template <typename T>
btnode<T>* BstFromPreorderHelper(vector<T>& preorder, int lo, int hi) {
  if (!preorder.size() || lo > hi) return NULL;
  btnode<T>* root = new btnode<T>(preorder[lo]);
  int leftTreeEndIdx = lo;
  for (int i = lo+1; i <= hi; i++) {
    if (preorder[i] < preorder[lo]) leftTreeEndIdx = i;
    else break;
  }
  root->left = BstFromPreorderHelper(preorder, lo+1, leftTreeEndIdx);
  root->right = BstFromPreorderHelper(preorder, leftTreeEndIdx+1, hi);
  if (root->left) root->left->parent = root;
  if (root->right) root->right->parent = root;
  return root;
}

template <typename T>
btnode<T>* BuildBstFromPreorder(vector<T>& preorder) {
  return BstFromPreorderHelper(preorder, 0, preorder.size()-1);
}

template <typename T>
void printInorder(btnode<T>* t) {
  if(t == NULL) return;
  printInorder(t->left);
  cout << t->data << endl;
  printInorder(t->right);
}

template <typename T>
btnode<T>* TreeFromLevelList(vector<T>& levellist) {
  if (!levellist.size() || levellist[0] == -1) return NULL;
  btnode<T>* root = new btnode<T>(levellist[0]);
  int lo = 1;
  queue<btnode<T>* > q;
  q.push(root);
  while (lo < levellist.size() && !q.empty()) {
    btnode<T>* tmp = q.front();
    q.pop();
    if (levellist[lo] != -1) {
      tmp->left = new btnode<T>(levellist[lo]);
      tmp->left->parent = tmp;
      q.push(tmp->left);
    }
    ++lo;
    if (lo < levellist.size()) {
	if (levellist[lo] != -1) {
	  tmp->right = new btnode<T>(levellist[lo]);
	  tmp->right->parent = tmp;
	  q.push(tmp->right);
	}
	++lo;
    }
  }
  return root;
}

int main() {
  vector<int> preorder = {43, 23, 37, 29, 31, 41, 47, 53};
  btnode<int>* t = BuildBstFromPreorder(preorder);
  //printInorder(t);
  deltree(t);
  vector<int> levellist = {5, 4, 7, 3, -1, 2, -1, 8, -1, 9};
  t = TreeFromLevelList(levellist);
  printInorder(t);
  deltree(t);
  return 0;
}
