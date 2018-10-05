#include <iostream>
#include <cassert>
#include "linkedlist.h"
using namespace std;

template <typename T>
sll<T>* intersection(sll<T>* l1, sll<T>* l2) {
  if (!l1 || !l2) return NULL;
  size_t szl1;
  size_t szl2;
  sll<T>* t1 = l1;
  sll<T>* t2 = l2;
  sll<T>* t1tail = NULL;
  sll<T>* t2tail = NULL;
  for(szl1 = 0, szl2 = 0 ; t1 || t2;) {
    if (t1) {
      szl1++;
      t1tail = t1;
      t1 = t1->next;
    }
    if (t2) {
      szl2++;
      t2tail = t2;
      t2 = t2->next;
    }
  }
  if (t1tail != t2tail) return NULL;
  t1 = l1;
  t2 = l2;
  if (szl1 > szl2) {
    for (size_t i = 0; i < szl1-szl2; i++, t1 = t1->next);
  }
  else {
    for (size_t i = 0; i < szl2-szl1; i++, t2 = t2->next);
  }
  for (; t1 && t2 && t1 != t2; t1 = t1->next, t2 = t2->next);
  return t1;
}

int main() {
  int a[] = {0, 1, 2, 3, 3, 4, 5, 5, 6};
  int b[] = {10, 9, 8, 7, 6};
  sll<int>* head1;
  sll<int>* head2;
  makesll<int>(a, sizeof(a)/sizeof(int), &head1);
  makesll<int>(b, sizeof(b)/sizeof(int), &head2);
  printsll<int>(head1);
  printsll<int>(head2);
  assert(!intersection(head1, head2));
  sll<int>* t2 = head1->next->next->next;
  sll<int>* t1 = t2->next;
  sll<int>* p1 = head2->next->next;
  sll<int>* p2 = p1->next;
  p1->next = t1;
  printsll<int>(head2);
  sll<int>* intr = intersection(head1, head2);
  assert(intr && intr->data == 3);
  t2->next = NULL;
  destroysll(head1);
  destroysll(head2);
  destroysll(p2);
  return 0;
}
