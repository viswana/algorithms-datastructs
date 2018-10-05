#include <iostream>
#include <string>
using namespace std;

int strToInt(const string& s) {
  bool sign = s[0] == '-' ? true : false;
  int i = sign ? 1 : 0;
  int y = 0;
  for (;i < s.size(); i++) {
    y = (y*10 + (s[i] - '0'));
  }
  if (sign) y = ~y + 1;
  return y;
}

string intToStr(int x) {
  string s;
  bool sign = x < 0 ? true : false;
  if (sign) x = x * -1;
  while (x) {
    s += (x % 10) + '0';
    x = x / 10;
  }
  if (sign) s += '-';
  return string(s.rbegin(), s.rend());
}

int main() {
  cout << strToInt("1234") << endl;
  cout << strToInt("-1234") << endl;
  cout << intToStr(123) << endl;
  cout << intToStr(-123) << endl;
}
