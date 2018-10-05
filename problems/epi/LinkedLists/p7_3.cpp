#include <iostream>
#include <cassert>
#include "linkedlist.h"
using namespace std;

template <typename T>
sll<T>* hasCycle(sll<T>* l) {
  if (!l) return l;
  if (!l->next) return l->next;
  sll<T>* slow = l->next;
  sll<T>* fast = l->next->next;
  for (; fast && fast->next && (slow != fast); slow = slow->next, fast = fast->next->next);
  int cyclelen = 1;
  if (slow == fast) {
    for (fast = fast->next; slow != fast; fast = fast->next) {
      cyclelen++;
    }
    slow = l;
    fast = l;
    while (cyclelen--) {
      fast = fast->next;
    }
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
  return NULL;
}

int main() {
  int a[] = {0, 1, 2, 3, 3, 4, 5, 5, 6};
  sll<int>* head;
  makesll<int>(a, sizeof(a)/sizeof(int), &head);
  printsll<int>(head);
  assert(!hasCycle(head));
  sll<int>* tail = head->next->next->next->next->next->next->next->next;
  tail->next = head->next->next->next->next;
  sll<int>* loopnode = hasCycle(head);
  assert(loopnode && loopnode->data == 3);
  tail->next = NULL;
  destroysll<int>(head);
  return 0;
}
