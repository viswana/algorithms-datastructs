#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int zeroonerand() {
  srand(time(NULL));
  return (rand() % 2);
}

unsigned int randint(int l, int u) {
  if (u < l) return -1;
  unsigned int places = u-l+1;
  unsigned int result;
  srand(time(NULL));
  do {
    result = 0;
    for (int i = 0; i < places; i++) {
      result = (result << 1) | (rand() % 2);
    }
  } while(result >= places);
  return result + l;
}

int main() {
  cout << randint(1, 6) << endl;
  return 0;
}
