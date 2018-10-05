#include <iostream>
using namespace std;

int main() {
  int sum = 0;
  for (int i = 0; i < 1000; i++) {
    if (!(i % 3) && !(i % 5)) sum +=i;
    else if (!(i % 5)) sum += i;
    else if (!(i % 3)) sum += i;
    else continue;
  }
  cout << sum << endl;
}
