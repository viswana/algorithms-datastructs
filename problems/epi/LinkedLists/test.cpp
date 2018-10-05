#include <iostream> 
using namespace std;

struct sll {
    struct sll* next;
    int data;
};

int reverseList(struct sll* l, struct sll* i, struct sll* j) {
    if (!l || !i) return -1;
    if (i == j) return 0;
    struct sll* tmp = NULL;
    while (l && l != i) {
        tmp = l;
        l = l->next;
    }
    struct sll* t1 = l;
    struct sll* t2 = tmp;
    while (l != j) {
        struct sll* x = l->next;
        l->next = tmp;
        tmp = l;
        l = x;
    }
    if (l) {
        struct sll* x = l->next;
        l->next = tmp;
        tmp = l;
        l = x;
        t2->next = tmp;
        t1->next = l;
    }
    else {
        t1->next = l;
        t2->next = tmp;
    }
    return 0;
}

int main() {
   struct sll x[10];
   for (int i = 0; i < 10; i++) {
       x[i].data = i;
       if (i < 9) x[i].next = &x[i+1];
   }
   x[9].next = NULL;
   struct sll* tmp = x;
   for (int i = 0; i < 10; i++) {
     cout << tmp->data << " ";
     tmp = tmp->next;
   }
   cout << endl;
   reverseList(x, &x[4], &x[5]);
   tmp = x;
   for (int i = 0; i < 10; i++) {
       cout << tmp->data << " ";
       tmp = tmp->next;
   }
   cout << endl;
   return 0;
}
