#include <iostream>
#include <string>
using namespace std;

int spsheetToInt(const string& s) {
  int acc = 0;
  for (int i = 0; i < s.size(); i++) {
    acc = acc*26 + ((s[i] - 'A') + 1);
  }
  return acc;
}

int main() {
  cout << spsheetToInt("BA") << endl;
  return 0;
}
