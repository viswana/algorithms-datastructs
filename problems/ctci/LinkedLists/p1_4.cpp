#include <iostream>
#include "linkedlist.h"
using namespace std;

template <typename T>
sll<T>* partition(sll<T>* head, T x) {
  if (!head) return NULL;
  sll<T>* lthead = NULL;
  sll<T>* lttail = NULL;
  sll<T>* gehead = NULL;
  for (; head; ) {
    sll<T>* tmp = head;
    head = head->next;
    if (tmp->data < x) {
      tmp->next = lthead;
      if (!lthead) lttail = tmp;
      lthead = tmp;
    }
    else {
      tmp->next = gehead;
      gehead = tmp;
    }
  }  
  if (!lthead) return gehead;
  lttail->next = gehead;
  return lthead;
}

int main() {
  int a[] = {0, 1, 2, 3, 3, 4, 5, 5, 6};
  sll<int>* head;
  makesll<int>(a, sizeof(a)/sizeof(int), &head);
  printsll<int>(head);
  head = partition(head, 3);
  printsll<int>(head);
  destroysll(head);
  return 0;
}
