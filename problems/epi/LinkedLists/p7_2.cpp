#include <iostream>
#include <cassert>
#include "linkedlist.h"
using namespace std;

template <typename T>
sll<T>* reverseSublist(sll<T>* l, int s, int f) {
  if (!l || s >= f || s <= 0 || f <= 0) return l;
  int delta = f-s;
  if (delta < 1) return l;
  sll<T>* head = l;
  sll<T>* tmp = NULL;
  while (l && s > 1) {
    tmp = l;
    l = l->next;
    s--;
  }  
  if (!l) return head;
  sll<T>* t1 = tmp;
  sll<T>* t2 = l;
  tmp = l;
  sll<T>* snode = l->next;
  delta--;
  while (delta && snode) {
    sll<T>* x = snode->next;
    snode->next = tmp;
    tmp = snode;
    snode = x;
    delta--;
  }
  if (!snode) {   
    if (!t1) {
      head = tmp;
    }
    else {
      t1->next = tmp;
    }
    t2->next = snode;
  }
  else {
    if (!t1) head = snode;
    else t1->next = snode;
    t2->next = snode->next;
    snode->next = tmp;
  }
  return head;
}

int main() {
  int a[] = {0, 1, 2, 3, 3, 4, 5, 5, 6};
  sll<int>* head1;
  makesll<int>(a, sizeof(a)/sizeof(int), &head1);
  printsll<int>(head1);
  printsll<int>(reverseSublist<int>(head1, 1, 10));
  return 0;
}
