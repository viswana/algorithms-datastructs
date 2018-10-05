#include <iostream>
#include "linkedlist.h"
using namespace std;

template <typename T>
bool isPalindrome(sll<T>* head) {
  if (!head || !head->next) return false;
  sll<T>* slow = head;
  sll<T>* fast = head;
  sll<T>* stack = NULL;
  for (; fast && fast->next;) {
    sll<T>* tmp = new sll<T>();
    tmp->data = slow->data;
    tmp->next = stack;
    stack = tmp;
    fast = fast->next->next;
    slow = slow->next;
  }
  if (fast) slow = slow->next;
  bool ret = true;
  for (; slow && stack; slow = slow->next, stack = stack->next) {
    if (slow->data != stack->data) {
      ret = false;
      break;
    }
  }
  destroysll<T>(stack);
  return ret;
}

int main() {
  int a[] = {0, 1, 2, 3, 4, 1, 0};
  sll<int>* head;
  makesll<int>(a, sizeof(a)/sizeof(int), &head);
  printsll<int>(head);
  cout << isPalindrome<int>(head) << endl;
  destroysll<int>(head);
  return 0;
}
