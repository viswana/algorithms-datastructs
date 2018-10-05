#include <iostream>
#include <unordered_map>
#include <vector>
#include "utils.h"
using namespace std;

template <typename T>
btnode<T>* FindNextLargest(btnode<T>* t, T key) {
  if (!t) return t;
  btnode<T>* largest_so_far = NULL;
  while (t) {
    if (key >= t->data) {
      t = t->right;
    }
    else {
      largest_so_far = t;
      t = t->left;
    }
  }
  return larges_so_far;
}
