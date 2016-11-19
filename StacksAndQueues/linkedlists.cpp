#include <iostream>

using namespace std;

typedef struct _sll {
  int i;
  struct _sll *next;
}sll, *psll;

void buildsll(int* x, size_t n, psll list) {
  if (x == NULL || n < 1 || list == NULL) return;
  for (size_t i = 0; i < n; i++) {
    list[i].i = x[i]; 
    if (i < n-1) list[i].next = list+i+1;
    else list[i].next = NULL;
  }
}

void printsll(psll head) {
  if (head == NULL) return;
  while (head != NULL) {
    cout << head->i << " ";
    head = head->next;
  }
  cout << endl;
}

psll findMiddle(psll head) {
  if (head == NULL) return head;
  psll drun = head;
  while (drun->next != NULL) {
    drun = drun->next->next;
    if (drun == NULL) break; //Even number of elements
    head = head->next;
  }
  return head;
}

psll findKthLast(psll head, size_t k) {
  if (head == NULL) return head;
  psll p1 = head;
  while(k > 0 && p1 != NULL) {
    p1 = p1->next;
    k--;
  }
  if (p1 == NULL) return NULL;
  while (p1 != NULL) {
    head = head->next;
    p1 = p1->next;
  }
  return head;
}

psll hasCycle(psll head) {
  if (head == NULL) return head;
  psll drun = head;
  psll tmp = head;
  while (drun->next != NULL) {
    drun = drun->next->next;
    if (drun == NULL) break;
    tmp = tmp->next;
    if (drun == tmp) break;
  }
  if (drun == NULL || drun->next == NULL) return NULL; //No loop
  tmp = head;
  while (tmp != drun) {
    tmp = tmp->next;
    drun = drun->next;
  }
  return tmp;
}

psll reverse(psll head) {
  if (head == NULL || head->next == NULL) return head;
  psll prev = NULL;
  while (head != NULL) {
    psll tmp = head->next;
    head->next = prev;
    prev = head;
    head = tmp;
  }
  return prev;
}

/** \brief reverse elements in chunks of size bucketsz
 *
 * The logic used, is reversing chuncks of the list that are
 * bucketsz in length and tying the new tail (old head) of the 
 * previous chunk to the tail of the next chunk (before reversing
 * the next chunk). The last chunk if runty (has size less than 
 * bucketsz), is not reversed.
 */
psll bucketReverse(psll head, size_t bucketsz) {
  if (head == NULL || bucketsz < 2) return head;
  psll t1 = NULL, tmptail = NULL;
  psll t2 = head, t3 = head, newhead = head;
  size_t i;
  do {
    psll t4;
    for (i = bucketsz; i > 0 && t3 != NULL; i--) {
      t4 = t3;
      t3 = t3->next;
    }
    if (i > 0) {
      if (tmptail) tmptail->next = t2;
    }
    else {
      //i == 0 && t3 == NULL || i == 0 && t3 != NULL
      if (tmptail) {
        tmptail->next = t4; 
      }
      else {
        newhead = t4;
      }
      tmptail = t2;
      while (t2 != t3) {
        psll tmp = t2->next;
        t2->next = t1;
        t1 = t2;
        t2 = tmp;
      }
    }
  } while (i == 0);
  return newhead;
}

psll pushfront(psll head, psll t) {
  if (t == NULL) return NULL;
  t->next = head;
  return t; 
}

psll pushback(psll head, psll t) {
  if (t == NULL) return NULL;
  t->next = NULL;
  if (head == NULL) {
    return t;
  }
  psll tmp = head;
  while (tmp != NULL) {
    if (tmp->next == NULL) {
      tmp->next = t;
      break;
    }
    tmp = tmp->next;
  }
  return head;
}

psll popfront(psll head) {
  if (head == NULL) return head;
  psll tmp = head->next;
  head->next = NULL;
  return tmp;
}

psll popback(psll head) {
  if (head == NULL) return NULL;
  psll tmp = NULL;
  while (head->next != NULL) {
    tmp = head;
    head = head->next;
  }
  if (tmp != NULL) tmp->next = NULL;
  return head;
}

size_t sllsize(psll head) {
  if (head == NULL) return 0;
  size_t sz = 0;
  while (head != NULL) {
    sz++;
    head = head->next;
  }
  return sz;
}

psll pushsortedsll(psll head, psll t) {
  if (t == NULL) return head;
  if (head == NULL) return t;
  psll t1 = NULL;
  psll oldhead = head;
  while (head != NULL && t->i > head->i) {
    t1 = head;
    head = head->next;
  }
  if (t1 == NULL) {
    t->next = head;
    return t;
  }
  else {
    t1->next = t;
    t->next = head;
    return oldhead;
  }
}

int main() {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  size_t len = sizeof(a)/sizeof(int);
  sll mysll[len];
  buildsll (a, len, mysll);
  printsll(mysll);
  cout << "Middle of the list is " << findMiddle(mysll)->i << endl;
  cout << "3rd last item is " << findKthLast(mysll, 3)->i << endl;
  //Make a loop
  mysll[len-1].next = &mysll[(len-1)/2];
  psll tmp = hasCycle(mysll);
  if (tmp != NULL) 
    cout << "Collision point is at " << hasCycle(mysll)->i << endl;
  else 
    cout << "No cycles" << endl;
  //Remove loop
  mysll[len-1].next = NULL;
  tmp = hasCycle(mysll);
  if (tmp != NULL) 
    cout << "Collision point is at " << hasCycle(mysll)->i << endl;
  else 
    cout << "No cycles" << endl;
  psll newhead = reverse(mysll);
  printsll(newhead);
  sll t = {100, NULL};
  newhead = pushfront(newhead, &t);
  printsll(newhead);
  sll t2 = {200, NULL};
  pushback(newhead, &t2);
  printsll(newhead);
  newhead = popfront(newhead);
  printsll(newhead);
  popback(newhead);
  printsll(newhead);
  int b[] = {1, 2, 3, 4, 5};
  size_t blen = sizeof(b)/sizeof(int);
  sll mysll2[blen];
  buildsll(b, blen, mysll2);
  psll bnhead = bucketReverse(mysll2, 2);
  printsll(bnhead);
  int c[] = {1, 2, 3, 4, 5, 6, 7, 8};
  size_t clen = sizeof(c)/sizeof(int);
  sll mysll3[clen];
  buildsll(c, clen, mysll3);
  psll cnhead = bucketReverse(mysll3, 3);
  printsll(cnhead);
  cout << sllsize(cnhead) << endl;
  int d[] = {1, 2, 3, 4, 6, 7, 8};
  size_t dlen = sizeof(d)/sizeof(int);
  sll mysll4[dlen];
  buildsll(d, dlen, mysll4);
  sll tx = {5, NULL};
  psll nhead = pushsortedsll(mysll4, &tx);
  printsll(nhead);
  sll ty = {0, NULL};
  nhead = pushsortedsll(nhead, &ty);
  printsll(nhead);
  sll tz = {9, NULL};
  nhead = pushsortedsll(nhead, &tz);
  printsll(nhead);
  return 0;
}
