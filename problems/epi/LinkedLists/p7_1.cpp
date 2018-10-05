#include <iostream>
#include <cassert>
#include "linkedlist.h"
using namespace std;

sll<int>* mergeSortedLists(sll<int>* l1, sll<int>* l2) {
  if (!l1 && !l2) return l1;
  if (!l2) return l2;
  else if (!l2) return l1;
  sll<int>* mhead = (l1->data <= l2->data) ? l1 : l2;
  while (l1 && l2) {
    sll<int>* tmp1 = NULL;
    sll<int>* tmp2 = NULL;    
    while (!tmp2 && l1 && (l1->data <= l2->data)) {
      tmp1 = l1;
      l1 = l1->next;
    }
    while (!tmp1 && l2 && (l2->data < l1->data)) {
      tmp2 = l2;
      l2 = l2->next;
    }
    if (tmp1) {
      tmp1->next = l2;
    }
    if (tmp2) {
      tmp2->next = l1;
    }
  }
  return mhead;
}

int main() {
  int a[] = {0, 1, 2, 3, 3, 4, 5, 5, 6};
  int b[] = {4, 5, 6, 7, 8};
  sll<int>* head1;
  sll<int>* head2;
  makesll<int>(a, sizeof(a)/sizeof(int), &head1);
  makesll<int>(b, sizeof(b)/sizeof(int), &head2);
  printsll<int>(head1);
  printsll<int>(head2);
  sll<int>* newhead = mergeSortedLists(head1, head2);
  assert(newhead);
  printsll<int>(newhead);
  destroysll<int>(newhead);
  return 0;
}
