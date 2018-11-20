#include <iostream>
using namespace std;

typedef enum _stk {
  s1,
  s2
} stk;

template <typename T>
class DualStack {
  size_t _sz;
  T* _arr;
  size_t _s1top;
  size_t _s2top;
public:
  DualStack(size_t sz) {
    _sz = sz;
    _arr = new T[sz+1];
    _s1top = 0;
    _s2top = sz+1;
  }
  ~DualStack() {
    delete[] _arr; 
  }
  int push(stk s, T x) {
    if (s == s1) {
      if (_s1top + 1 == _s2top) return -1;
      _s1top++;
      _arr[_s1top] = x;
    }
    else {
      if (_s2top - 1 == _s1top) return -1;
      _s2top--;
      _arr[_s2top] = x;
    }
    return 0;
  }
  int pop(stk s) {
    if (s == s1) {
      if (!_s1top) return -1;
      _s1top--;
    }
    else {
      if (_s2top == _sz+1) return -1;
      _s2top++;
    }
    return 0;
  }
  int top(stk s, T* out) {
    if (!out) return -1;
    if (s == s1) {
      if (!_s1top) return -1;
      *out = _arr[_s1top];
    }
    else {
      if (_s2top == _sz+1) return -1;
      *out = _arr[_s2top];
    }
    return 0;
  }
  bool empty(stk s) {
    return (s == s1) ? (!_s1top) : (_s2top == _sz+1);
  }
  friend ostream& operator << (ostream& out, const DualStack<T>& ds) {
    out << "Printing s1" << endl;
    for (size_t j = ds._s1top; j > 0; j--)
      out << ds._arr[j] << ", ";
    out << endl;
    out << "Printing s2" << endl;
    for (size_t j = ds._s2top; j < ds._sz+1; j++)
      out << ds._arr[j] << ", ";
    out << endl;
    return out;
  }
};

int main() {
  DualStack<int> ds(4);
  cout << ds.push(s1, 10) << endl;
  cout << ds.push(s2, 20) << endl;
  cout << ds.push(s1, 30) << endl;
  cout << ds.push(s2, 40) << endl;
  int out;
  if (!ds.top(s1, &out))
    cout << out << endl;
  if (!ds.top(s2, &out))
    cout << out << endl;
  cout << ds;
  cout << ds.pop(s1) << endl;
  cout << ds.pop(s2) << endl;
  cout << ds.pop(s1) << endl;
  cout << ds.pop(s2) << endl;
  return 0;
}
