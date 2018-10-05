#include <iostream>
#include "linkedlist.h"
using namespace std;

template <typename T>
sll<T>* kthtolast(sll<T>* head, size_t k) {
  if (!head) return NULL;
  sll<T>* p1 = head;
  for (size_t i = 0; i < k && p1; i++) {
    p1 = p1->next;
  }
  if (!p1) return NULL;
  sll<T>* p2 = head;
  //Go till p1->next != NULL since if k = 0, p2 will have to point to the tail node rather than NULL
  for (;p1->next != NULL; p1 = p1->next, p2 = p2->next);
  return p2;
}

int main() {
  int a[] = {0, 1, 2, 3, 3, 4, 5, 5, 6};
  sll<int>* head;
  makesll<int>(a, sizeof(a)/sizeof(int), &head);
  printsll<int>(head);
  sll<int>* k = kthtolast(head, 3);
  cout << k->data << endl;
  destroysll(head);
  return 0;
}
