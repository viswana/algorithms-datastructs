#include <iostream>
#include <utility>

using namespace std;

bool isOverlappingRects(pair<pair<int, int>, pair<int, int> > r1, pair<pair<int, int>, pair<int, int> > r2) {

}

int main() {
  cout << isOverlappingRects(make_pair(make_pair(2, 2), make_pair(5, 0)), make_pair(make_pair(3, 2), make_pair(10, 0))) << endl;
  return 0;
}
