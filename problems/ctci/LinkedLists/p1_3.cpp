#include <iostream>
#include "linkedlist.h"
using namespace std;

template <typename T>
int delMiddleNode(sll<T>* t) {
  if (!t || !t->next) return -1;
  sll<T>* tmp = t->next;
  t->data = tmp->data;
  t->next = tmp->next;
  delete(tmp);
  return 0;
}

int main() {
  int a[] = {0, 1, 2, 3, 3, 4, 5, 5, 6};
  sll<int>* head;
  makesll<int>(a, sizeof(a)/sizeof(int), &head);
  printsll<int>(head);
  delMiddleNode(head->next->next);
  printsll(head);
  destroysll(head);
  return 0;
}
