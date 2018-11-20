#include <iostream>
using namespace std;

template <typename T>
class cqueue {
protected:
  size_t _cap;
  size_t _head;
  size_t _tail;
  T* _arr;
  size_t _sz;
public:
  cqueue(size_t cap) {
    _cap = cap;
    _head = 0;
    _tail = 0;
    _sz = 0;
    _arr = new T[_cap+1];
  }
  ~cqueue() {
    delete[] _arr;
  }
  int enqueue(T x) {
    ++_tail;
    if (_tail > _cap)
      _tail = 0;
    if (_tail == _head) {
      if (!_tail) _tail = _cap;
      else --_tail;
      return -1;
    }
    if (!_tail) _arr[_cap] = x;
    else _arr[_tail-1] = x;
    ++_sz;
    return 0;
  }
  int dequeue() {
    if (_head == _tail) return -1;
    ++_head;
    if (_head > _cap) _head = 0;
    --_sz;
    return 0;
  }
  int front(T* out) {
    if (_head == _tail || !out) return -1;
    *out = _arr[_head];
    return 0;
  }
  bool empty() {
    return _head == _tail;
  }
  size_t size() {
    return _sz;
  }
  friend ostream& operator << (ostream& out, const cqueue& q) {
    for (size_t i = q._head; i != q._tail;) {
      out << q._arr[i] << ", ";
      ++i;
      if (i > q._cap) i = 0;
    }
    out << endl;
    return out;
  }
};

template <typename T>
class cdequeue : public cqueue<T> {
public:
  cdequeue (size_t sz) : cqueue<T>(sz) {}
  int pushfront(T x) {
    if (!this->_head) this->_head = this->_cap;
    else --this->_head;
    if (this->_head == this->_tail) {
      if (this->_head == this->_cap) this->_head = 0;
      else ++this->_head;
      return -1;
    }
    this->_arr[this->_head] = x;
    ++this->_sz;
    return 0;
  }
  int popback() {
    if (this->_head == this->_tail) return -1;
    if (!this->_tail) this->_tail = this->_cap;
    else --this->_tail;
    --this->_sz;
    return 0;
  }
};

int main() {
  cdequeue<int> q(2);
  cout << q.enqueue(20) << endl;
  cout << q.pushfront(30) << endl;
  cout << q.enqueue(40) << endl;
  cout << q;
  cout << q.popback() << endl;
  cout << q;
  cout << q.popback() << endl;
  cout << q.dequeue() << endl;
  return 0;
}
