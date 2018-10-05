#include <iostream>
#include <cassert>
#include "linkedlist.h"
using namespace std;

sll<int>* sumLists(sll<int>* head1, sll<int>* head2) {
  if (!head1 || !head2) return NULL;
  int carry = 0;
  sll<int>* res = NULL;
  sll<int>* tail = NULL;
  for (;head1 || head2;) {
    int s1 = 0;
    int s2 = 0;
    if (head1) {
      s1 = head1->data;
      head1 = head1->next;
    }
    if (head2) {
      s2 = head2->data;
      head2 = head2->next;
    }
    sll<int>* tmp = new sll<int>();
    tmp->data = (s1+s2+carry)%10;
    if (s1+s2+carry > 9) carry = 1;
    else carry = 0;
    tmp->next = NULL;
    if (!res) {
      res = tmp;
    }
    else {
      tail->next = tmp;
    }
    tail = tmp;
  }
  if (carry) {
    sll<int>* tmp = new sll<int>();
    tmp->data = 1;
    tmp->next = NULL;
    tail->next = tmp;
  }
  return res;
}

int main() {
  int a[] = {9, 9, 9};
  int b[] = {1};
  sll<int>* head1;
  sll<int>* head2;
  makesll<int>(a, sizeof(a)/sizeof(int), &head1);
  makesll<int>(b, sizeof(b)/sizeof(int), &head2);
  printsll<int>(head1);
  printsll<int>(head2);
  sll<int>* res = sumLists(head1, head2);
  printsll<int>(res);
  destroysll<int>(head1);
  destroysll<int>(head2);
  destroysll<int>(res);
  return 0;
}
