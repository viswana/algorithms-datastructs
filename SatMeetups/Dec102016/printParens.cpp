#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_set>
using namespace std;

//Using Hashset to avoid duplicates
vector<string> printParens1(int n) {
  if (n == 0) return vector<string>();
  if (n == 1) return vector<string>(1, string("()"));
  vector<string> out;
  vector<string> p = printParens1(n-1);
  unordered_set<string> x;
  for (size_t j = 0; j < p.size(); j++) {
    for (size_t i = 0; i < p[j].size(); i++) {
      if (p[j][i] == '(') {
        string tmp = p[j].substr(0, i+1) + "()" + p[j].substr(i+1, p[j].size()-i-1);
        if (!x.count(tmp)) {
          x.insert(tmp);
          out.push_back(tmp);
        }
      }
    }
    if (j == p.size()-1) out.push_back(p[j] + "()");
  }
  return out;
}

//Using recursive tree method
void printParens2H(vector<string>& out, int leftrem, int rightrem, char* s, size_t idx) {
  if (leftrem < 0 || rightrem < leftrem) return;
  if (leftrem == 0 && rightrem == 0) out.push_back(s);
  else {
    s[idx] = '(';
    printParens2H(out, leftrem-1, rightrem, s, idx+1);
    s[idx] = ')';
    printParens2H(out, leftrem, rightrem-1, s, idx+1);
  }
}

vector<string> printParens2(size_t n) {
  if (n == 0) return vector<string>();
  char s[n*2+1];
  s[n*2] = '\0';
  vector<string> out;
  printParens2H(out, n, n, s, 0);
  return out;
}

int main(int argc, char* argv[]) {
  if (argc < 2) return -1;
  size_t n = strtoul(argv[1], NULL, 10);
  cout << "Calling printPraens1" << endl;
  auto i = printParens1(n);
  cout <<  "Size of vector is " << i.size() << endl;
  for (size_t j = 0; j < i.size(); j++) {
    cout << i[j] << endl;
  }
  cout << "calling printParens2" << endl;
  i = printParens2(n);
  cout <<  "Size of vector is " << i.size() << endl;
  for (size_t j = 0; j < i.size(); j++) {
    cout << i[j] << endl;
  }
  return 0;
}
