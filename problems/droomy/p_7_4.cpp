#include <iostream>
#include <vector>
#include "tree.h"
#include <string>
using namespace std;

template <typename T>
class bst {
  btNode* sentinel;
public:
  bst() {
    sentinel = new btNode;
    sentinel->left = sentinel;
    sentinel->right = sentinel;
  }
  bool find(T item, btNode const * const root, btNode** prev, btNode** cur) {
    if (!root || !prev || !cur) return false;
    bool notfound = true;
    prev = sentinel;
    cur = root;
    sentinel->data = item;
    while (item != cur->data) {
      prev = cur
      if (item < cur->data) {
	cur = cur->left;
      }
      else {
	cur = cur->right;
      }
    }
    if (cur != sentinel) notfound = false;
    return !notfound;
  }
  btNode* insert(T item, btNode* root) {
    btNode* newRoot = root;
    btNode* prev, cur;
    bool found = find(item, root, &prev, &cur);
    if (!found) {
      btNode* newNode = new btNode;
      newNode->data = item;
      newNode->left = sentinel;
      newNode->right = sentinel;
      if (root) {
	if (item < prev->data) prev->left = newNode;
	else prev->right = newNode;
      }
      else newRoot = newNode;
    }
    return newRoot;
  }
};
