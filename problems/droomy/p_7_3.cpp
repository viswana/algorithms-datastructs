#include <iostream>
#include <vector>
#include "list.h"
using namespace std;

template <typename T>
class Sll {
  size_t _flhead;
  size_t _cap;
  size_t allocNode() {
    size_t newNode = _flhead;
    _flhead = sll[_flhead].next;
    sll[newNode].next = 0;
    return newNode;
  }
  void freeNode(size_t idx) {
    sll[idx].next = _flhead;
    _flhead = idx;
  }
public:
  vector<SllNode<T> > sll;
  Sll(size_t cap) {
    _cap = cap;
    sll.resize(cap+1);
    sll[0].next = 0;
    if (!cap) {
      _flhead = 0;
    }
    else {
      _flhead = 1;
      for (size_t i = 1; i < cap; ++i) {
	sll[i].next = i+1;
      }
      sll[cap].next = 0;
    }
  }
  size_t push_front(T item, size_t head) {
    if (_flhead) {
      size_t newNode = allocNode();
      sll[newNode].data = item;
      sll[newNode].next = head;
      return newNode;
    }
    if (!_cap) {
      SllNode<T> x = {item, head};
      sll.push_back(x);
      return sll.size()-1;
    }
    return 0;
  }
  size_t pop_front(size_t head) {
    if (head) {
      size_t node = head;
      head = sll[head].next;
      freeNode(node);
    }
    return head;
  }
  ostream& print_list(ostream& out, size_t head) {
    for (size_t i = head; i; ) {
      out << sll[i].data << ", ";
      i = sll[i].next;
    }
    out << endl;
    return out;
  }
  bool find(T item, size_t head, size_t& prev, size_t& cur) {
    bool notfound = true;
    prev = 0;
    cur = head;
    if (!head) return notfound;
    sll[0].data = item;
    while (item > sll[cur].data) {
      prev = cur;
      cur = sll[cur].next;
    }
    if (cur && sll[cur].data == item) {
      notfound = false;
    }
    return !notfound;
  }
  size_t insert(T item, size_t head) {
    if (_cap && !_flhead) return 0;
    size_t prev, cur;
    size_t newhead = head;
    find(item, head, prev, cur);
    size_t newnode;
    if (_flhead) {
      newnode = allocNode();
      sll[newnode].data = item;
      sll[newnode].next = cur;
    }
    else {
      SllNode<T> x = {item, cur};
      sll.push_back(x);
      newnode = sll.size()-1;
    }
    if (prev) {
      sll[prev].next = newnode;
    }
    else {
      newhead = newnode;
    }
    return newhead;
  }
  size_t del(T item, size_t head) {
    if (!head) return head;
    size_t prev, cur;
    size_t newhead = head;
    bool found = find(item, head, prev, cur);
    if (!found) return head;
    if (prev) {
      sll[prev].next = sll[cur].next;
    }
    else {
      newhead = sll[cur].next;
    }
    freeNode(cur);
    return newhead;
  }
};

int main() {
  Sll<int> sll(20);
  size_t head = 0;
  for (size_t i = 20; i >= 4; i -= 2) {
    size_t t = sll.push_front(i, head);
    if (t) head = t;
  }
  sll.print_list(cout, head);
  head = sll.insert(9,  head);
  sll.print_list(cout, head);
  head = sll.del(4, head);
  sll.print_list(cout, head);
  head = sll.insert(1, head);
  sll.print_list(cout, head);
  head = sll.del(20, head);
  sll.print_list(cout, head);
  head = sll.insert(30, head);
  sll.print_list(cout, head);
  head = sll.insert(30, head);
  sll.print_list(cout, head);
  return 0;
}
