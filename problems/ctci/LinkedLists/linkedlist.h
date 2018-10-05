#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>
using namespace std;

template <typename T>
class sll {
 public:
  T data;
  sll<T>* next;
};

template <typename T>
class dll {
 public:
  T data;
  dll<T>* prev;
  dll<T>* next;
};

template <typename T>
int makesll(T* arr, size_t sz, sll<T>** head) {
  if (!arr || !head || sz < 1) return -1;
  *head = new sll<T>();
  (*head)->data = arr[0];
  (*head)->next = NULL;
  sll<T>* tmp1 = *head;
  for (size_t i = 1; i < sz; i++) {
    sll<T>* tmp = new sll<T>();
    tmp->data = arr[i];
    tmp->next = NULL;
    tmp1->next = tmp;
    tmp1 = tmp;
  }
  return 0;
}

template <typename T>
void destroysll(sll<T>* head) {
  while (head) {
    sll<T>* tmp = head;
    head = head->next;
    delete tmp;
  }
}

template <typename T>
void printsll(sll<T>* head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

template <typename T>
sll<T>* reversesll(sll<T>* head) {
  if (!head || !head->next) return head;
  sll<T>* tmp1 = NULL;
  sll<T>* tmp = head;
  while (head->next) {
    head = head->next;
    tmp->next = tmp1;
    tmp1 = tmp;
    tmp = head;
  }
  head->next = tmp1;
  return head;
}
#endif
