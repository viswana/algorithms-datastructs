#include <iostream>
using namespace std;

class Coord {
public:
  int x;
  int y;
};

class Rect {
public:
  Coord left, right;
};

bool isIntersect(const Rect& a, const Rect& b) {
  return (b.left.x <= a.right.x && b.right.x >= a.left.x && b.left.y <= a.right.y && b.right.y >= a.left.y);
}

bool intersectingRect(const Rect& a, const Rect& b, Rect* c) {
  bool ret = isIntersect(a, b);
  if (ret) {
    (c->left).x = (a.left.x > b.left.x) ? a.left.x : b.left.x;
    (c->right).x = (a.right.x > b.right.x) ? b.right.x : a.right.x;
    (c->left).y = (a.left.y > b.left.y) ? a.left.y : b.left.y;
    (c->right).y = (a.right.y > b.right.y) ? b.right.y : a.right.y;
  }
  return ret;
}

int main() {
  Rect a = {{0,5}, {20, 10}};
  Rect b = {{5,0}, {25, 5}};
  Rect c;
  if (intersectingRect(a, b, &c))
    cout << "(" <<c.left.x << ", " << c.left.y << ")" << ", " << "(" <<c.right.x << ", " << c.right.y << ")" << endl;
  return 0;
}
