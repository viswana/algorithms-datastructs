#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

class medianheap {
private:
  priority_queue<int, vector<int> > _maxheap;
  priority_queue<int, vector<int>, greater<int> > _minheap;
  double _median;
public:
  medianheap(vector<int>& a) {
    if (a.size() > 1) {
      if (a[1] > a[0]) {
	_maxheap.push(a[0]);
	_minheap.push(a[1]);
      }
      else {
	_maxheap.push(a[1]);
	_minheap.push(a[0]);
      }
      _median = (a[0] + a[1])/2;
      for (int i = 2; i < a.size() && !_minheap.empty() && !_maxheap.empty(); i++) {
	if (a[i] > _minheap.top()) _minheap.push(a[i]);
	else if (a[i] < _maxheap.top()) _maxheap.push(a[i]);
	else _minheap.push(a[i]);
	if (_minheap.size() == _maxheap.size()) {
	  _median = (_minheap.top() + _maxheap.top())/2;
	}
	else if (_minheap.size() == _maxheap.size() + 1)
	  _median = _minheap.top();
	else if (_maxheap.size() == _minheap.size() + 1)
	  _median = _maxheap.top();
	else if (_minheap.size() > _maxheap.size() + 1) {
	  _maxheap.push(_minheap.top());
	  _minheap.pop();
	}
	else {
	  _minheap.push(_maxheap.top());
	  _maxheap.pop();
	}
      }
    }
  }
};

  

int main() {
  int a[] = {13, 5, 26, 18, 99, 34, 24};
  priority_queue<int, vector<int>, greater<int> > p(a, a+sizeof(a)/sizeof(int));
  for (int i = 0; i < sizeof(a)/sizeof(int); i++) {
    cout << p.top() << " ";
    p.pop();
  }
  cout << endl;
  return 0;
}
