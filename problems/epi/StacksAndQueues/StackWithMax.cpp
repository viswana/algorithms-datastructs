#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class StackWithMax {
private:
  class snode {
  public:
    T data;
    size_t count;
    snode(T item, size_t cnt) : data(item), count(cnt) {};
  };
  stack<T> _s1;
  stack<snode> _s2;
public:
  void push(const T& item) {
    _s1.push(item);
    if (!_s2.empty()) {
      if (_s2.top().data < item) _s2.push(snode(item, 1));
      else if (_s2.top().data == item) _s2.top().count++;
    }
    else _s2.push(snode(item, 1));
  }
  T const * const top() {
    if (_s1.empty()) return NULL;
    return &_s1.top();
  }
  void pop() {
    if (_s1.empty()) return;
    if (_s1.top() == _s2.top().data) {
      if (_s2.top().count == 1) _s2.pop();
      else _s2.top().count--;
    }
    _s1.pop();
  }
  int max(T * const data) {
    if (_s2.empty() || !data) return -1;
    *data = _s2.top().data;
    return 0;
  }
};

int main() {
  int a[] = {5, 1, 3, 7, 7, 8, 2, 4, 5};
  StackWithMax<int> s;
  for (int x : a) {
    s.push(x);
  }
  //s.print();
  int dat;
  s.max(&dat);
  cout << "Current Max is " << dat << endl;
  s.pop(); s.pop(); s.pop(); s.pop();
  s.max(&dat);
  cout << "Current Max is " << dat << endl;
  s.pop();
  s.max(&dat);
  cout << "Current Max is " << dat << endl;
  s.pop();s.pop();s.pop();
  s.max(&dat);
  cout << "Current Max is " << dat << endl;
  s.pop();
  cout << "Current Max is " << s.max(&dat) << endl;
  return 0;
}
