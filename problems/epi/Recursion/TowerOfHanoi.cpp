#include <iostream>
#include <stack>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;


void TowerOfHanoiHelper(vector<stack<int> >& pegs, unsigned int numrings, vector<vector<int> >& result, int from_peg, int to_peg, int buffer_peg) {
  if (numrings > 0) {
    TowerOfHanoiHelper(pegs, numrings-1, result, from_peg, buffer_peg, to_peg);
    pegs[to_peg].push(pegs[from_peg].top());
    pegs[from_peg].pop();
    vector<int> move = {from_peg, to_peg};
    result.push_back(move);
    TowerOfHanoiHelper(pegs, numrings-1, result, buffer_peg, to_peg, from_peg);
  }
}

struct callparams {
  int numrings;
  int from_peg;
  int to_peg;
  int buffer_peg;
};

vector<vector<int> > TowerOfHanoiI(int numpegs, int numrings) {
  vector<stack<int> > pegs(numpegs);
  for (int i = numrings; i >= 1; --i)
    pegs[0].push(i);
  vector<vector<int> > result;
  stack<struct callparams> callstack;
  if (numrings) callstack.push({numrings, 0, 1, 2});
  int state = 0;
  while (!callstack.empty()) {
    if (state == 0) {
      struct callparams tmp = callstack.top();
      if (tmp.numrings > 1) {
	callstack.push({tmp.numrings-1, tmp.from_peg, tmp.buffer_peg, tmp.to_peg});
      }
      else state = 1;
    }
    else {
      struct callparams tmp = callstack.top();
      callstack.pop();
      pegs[tmp.to_peg].push(pegs[tmp.from_peg].top());
      pegs[tmp.from_peg].pop();
      vector<int> move = {tmp.from_peg, tmp.to_peg};
      result.push_back(move);
      if (tmp.numrings > 1) {
	callstack.push({tmp.numrings-1, tmp.buffer_peg, tmp.to_peg, tmp.from_peg});
	state = 0;
      }
    }
  }
  return result;
}

vector<vector<int> > TowerOfHanoi(unsigned int numpegs, unsigned int numrings) {
  vector<vector<int> > result;
  vector<stack<int> > pegs(numpegs);
  for (int i = numrings; i >= 1; i--)
    pegs[0].push(i);
  TowerOfHanoiHelper(pegs, numrings, result, 0, 1, 2);
  return result;
}

int main() {
  const unsigned int NUMPEGS = 3;
  const int numrings = 10;
  auto result1 = TowerOfHanoi(NUMPEGS, numrings);
  auto result2 = TowerOfHanoiI(NUMPEGS, numrings);
  auto numMoves = pow(2, numrings) - 1;
  assert(result1.size() == numMoves);
  assert(result2.size() == numMoves);
  for (int i = 0; i < numMoves; i++) {
    for (int j = 0; j < 2; j++)
      assert(result1[i][j] == result2[i][j]);
  }
  return 0;
}
