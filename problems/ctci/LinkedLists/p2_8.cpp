#include <iostream>
#include <cassert>
#include "linkedlist.h"
using namespace std;

template <typename T>
sll<T>* isLoop(sll<T>* head) {
  if (!head) return head;
  if (!head->next) return NULL;
  //Move one iteration so slow and fast are unequal
  sll<T>* slow = head->next;
  sll<T>* fast = head->next->next;
  for(;fast && fast->next && slow != fast; slow = slow->next, fast = fast->next->next);
  if (slow == fast) {
    slow = head;
    for (;slow != fast; slow = slow->next, fast = fast->next);
    return slow;
  }
  return NULL;
}

int main() {
  int a[] = {0, 1, 2, 3, 3, 4, 5, 5, 6};
  sll<int>* head;
  makesll<int>(a, sizeof(a)/sizeof(int), &head);
  printsll<int>(head);
  assert(!isLoop(head));
  sll<int>* tail = head->next->next->next->next->next->next->next->next;
  tail->next = head->next->next->next->next;
  sll<int>* loopnode = isLoop(head);
  assert(loopnode && loopnode->data == 3);
  tail->next = NULL;
  destroysll<int>(head);
  return 0;
}
