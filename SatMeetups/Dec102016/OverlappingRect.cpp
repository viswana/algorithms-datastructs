#include <iostream>
#include <utility>

using namespace std;

bool isOverlappingRects(pair<pair<int, int>, pair<int, int> > r1, pair<pair<int, int>, pair<int, int> > r2) {
  if (r1.second.first < r2.first.first || r2.second.first < r1.first.first || r1.second.second > r2.first.second || r2.second.second > r1.first.second) return false;
  return true; 
}

int main() {
  cout << isOverlappingRects(make_pair(make_pair(2, 2), make_pair(5, 0)), make_pair(make_pair(6, 2), make_pair(10, 0))) << endl;
  cout << isOverlappingRects(make_pair(make_pair(2, 2), make_pair(5, 0)), make_pair(make_pair(4, 2), make_pair(10, 0))) << endl;
  cout << isOverlappingRects(make_pair(make_pair(2, 2), make_pair(5, 0)), make_pair(make_pair(2, 6), make_pair(10, 4))) << endl;
  cout << isOverlappingRects(make_pair(make_pair(2, 2), make_pair(5, 0)), make_pair(make_pair(2, 6), make_pair(10, 1))) << endl;
  return 0;
}
