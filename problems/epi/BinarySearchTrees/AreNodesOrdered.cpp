#include <iostream>
#include "utils.h"
using namespace std;

template <typename T>
bool findBstNode(btnode<T>* s, btnode<T>* t) {
  while (s && t && s != t) {
    if (t->data <= s->data) s = s->left;
    else s = s->right;
  }
  if (s == t) return true;
  return false;
}

template <typename T>
bool AreBstNodesOrdered(btnode<T>* n1, btnode<T>* n2, btnode<T>* middle) {
  if (!middle && (!n1 || !n2)) return false;
  btnode<T>* tmp1 = n1;
  btnode<T>* tmp2 = n2;
  while (tmp1 != middle && tmp2 != middle && tmp1 != tmp2) {
    if (tmp1) {
      if (middle->data >= tmp1->data) tmp1 = tmp1->right;
      else tmp1 = tmp1->left;
    }
    if (tmp2) {
      if (middle->data >= tmp2->data) tmp2 = tmp2->right;
      else tmp2 = tmp2->left;
    }
  }
  if (tmp1 == tmp2) return false;
  if (tmp1 == middle) return findBstNode(middle, n2);
  else return findBstNode(middle, n1);
}
