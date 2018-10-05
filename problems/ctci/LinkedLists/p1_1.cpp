#include <iostream>
#include <unordered_set>
#include "linkedlist.h"
using namespace std;

template <typename T>
void deDup1(sll<T>* head) {
  if (!head) return;
  sll<T>* tmp = head;
  sll<T>* tmp1 = NULL;
  unordered_set<T> s;
  while (tmp != NULL) {
    if (s.count(tmp->data)) {
      tmp1->next = tmp->next;
      delete(tmp);
      tmp = tmp1->next;
    }
    else {
      s.insert(tmp->data);
      tmp1 = tmp;
      tmp = tmp->next;
    }
  }
}

template <typename T>
void deDup2(sll<T>* head) {
  for (sll<T>* p1 = head; p1->next != NULL; p1 = p1->next) {
    sll<T>* tmp = p1;
    for (sll<T>* p2 = p1->next; p2 != NULL;) {
      if (p1->data == p2->data) {
	tmp->next = p2->next;
	delete(p2);
	p2 = tmp->next;
      }
      else {
	tmp = p2;
	p2 = p2->next;
      }
    }
  }
}

int main() {
  int a[] = {0, 1, 2, 3, 3, 4, 5, 5, 6};
  sll<int>* head;
  makesll<int>(a, sizeof(a)/sizeof(int), &head);
  printsll<int>(head);
  deDup2(head);
  printsll<int>(head);
  destroysll(head);
  return 0;
}
