#include <iostream>
#include <cassert>
#include "linkedlist.h"
using namespace std;

template <typename T>
sll<T>* reverseSublist(sll<T>* l, int s, int f) {
  if (!l || s >= f || s <= 0 || f <= 0) return NULL;
  int delta = f-s;
  if (delta < 1) return l;
  sll<T>* head = l;
  sll<T>* tmp = NULL;
  while (l && s > 1) {
    tmp = l;
    l = l->next;
    s--;
  }
  if (!l) return NULL;
  sll<T>* snode = l;
  sll<T>* tmp1 = tmp;
  while (delta && l) {
    tmp1 = l;
    l = l->next;
    delta--;
  }
  sll<T>* fnode;
  if (!l) fnode = tmp1;
  else fnode = l;
  if (tmp) {
    tmp->next = fnode;
  }
  else {
    head = fnode;
  }
  tmp = snode;
  snode = snode->next;
  tmp->next = fnode->next;
  while(snode != fnode) {
    sll<T>* x = snode->next;
    snode->next = tmp;
    tmp = snode;
    snode = x;
  }
  fnode->next = tmp;
  return head;
}

int main() {
  int a[] = {0, 1, 2, 3, 3, 4, 5, 5, 6};
  sll<int>* head1;
  makesll<int>(a, sizeof(a)/sizeof(int), &head1);
  printsll<int>(head1);
  printsll<int>(reverseSublist(a, 4, 7));
  return 0;
