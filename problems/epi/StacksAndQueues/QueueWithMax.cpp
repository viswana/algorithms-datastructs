#include <iostream>
#include <queue>
#include <deque>
using namespace std;

template <typename T>
class QueueWithMax {
private:
  class qnode {
  public:
    T data;
    size_t count;
    qnode(T item, size_t cnt) : data(item), count(cnt) {};
  };
  queue<T> _q1;
  deque<qnode> _q2;
public:
  void push(const T& item) {
    _q1.push(item);
    while (!_q2.empty() && _q2.back().data < item) _q2.pop_back();
    if (!_q2.empty()) {
      if (_q2.back().data == item) _q2.back().count++;
      else _q2.push_back(qnode(item, 1));
    }
    else _q2.push_back(qnode(item, 1));
  }
  void pop() {
    if (_q1.empty()) return;
    if (_q2.front().data == _q1.front()) {
      if (_q2.front().count == 1) _q2.pop_front();
      else _q2.front().count--;
    }
    _q1.pop();
  }
  T const * const front() {
    if (_q1.empty()) return NULL;
    return &_q1.front();
  }
  int max(T * const data) {
    if (_q1.empty() || !data) return -1;
    *data = _q2.front().data;
    return 0;
  }
};

int main() {
  int a[] = {5, 1, 3, 7, 7, 8, 2, 4, 5};
  QueueWithMax<int> s;
  for (int x : a) {
    s.push(x);
  }
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
