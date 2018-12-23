#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

typedef struct _node {
  struct _node* next;
  int data;
} node, *pnode;

void makell(int* a, size_t n, pnode ll) {
  if (!a || n < 1 || !ll) return;
  for (size_t i = 0; i < n-1; ++i) {
    ll[i].data = a[i];
    ll[i].next = ll+i+1;
  }
  ll[n-1].data = a[n-1];
  ll[n-1].next = NULL;
}

void printll(pnode ll) {
  if (!ll) return;
  for (; ll; ll = ll->next) {
    cout << ll->data << ",";
  }
  cout << endl;
}

pnode partition(pnode head, int x) {
  if (!head) return head;
  pnode prev1 = NULL;
  pnode cur1 = head;
  pnode prev2 = NULL;
  pnode cur2 = head;
  while (cur2 && cur2->data <= x) {
    prev1 = cur1;
    cur1 = cur1->next;
    prev2 = cur2;
    cur2 = cur2->next;
  }
  if (cur1 == head) {
    while (cur2 && cur2->data > x) {
      prev2 = cur2;
      cur2 = cur2->next;
    }
    if (cur2) {
      head = cur2;
      //swap head with cur2
      prev2->next = cur1;
      pnode tmp = cur1->next;
      cur1->next = cur2->next;
      cur2->next = tmp;
      //Adjust pointers
      prev1 = cur2;
      cur1 = cur2->next;
      prev2 = cur1;
      cur2 = cur1->next;
    }
  }
  while (cur2) {
    if (cur2->data <= x) {
      //swap cur1 and cur2
      prev1->next = cur2;
      prev2->next = cur1;
      pnode tmp = cur1->next;
      cur1->next = cur2->next;
      cur2->next = tmp;
      //Adjust pointers
      prev1 = cur2;
      cur1 = cur2->next;
      prev2 = cur1;
      cur2 = cur1->next;
    }
    else {
      prev2 = cur2;
      cur2 = cur2->next;
    }
  }
  return head;
}

bool valpartition(pnode head, int x) {
  if (!head) return true;
  for (; head && head->data <= x; head = head->next);
  for (; head && head->data > x; head = head->next);
  if (head) return false;
  else return true;
}

int main() {
  srand(time(NULL));
  size_t sz = 10;
  int numtests = 2;
  while (numtests) {
    int a[sz];
    for (size_t i = 0; i < sz; ++i) {
      a[i] = rand() % (sz*sz*sz);
    }
    node ll[sz];
    makell(a, sz, ll);
    printll(ll);
    int pivot = rand() % (sz*sz*sz);
    cout << "Pivot is " << pivot << endl;
    pnode head = partition(ll, pivot);
    printll(head);
    assert(valpartition(head, pivot));
    --numtests;
  }
  return 0;
}
