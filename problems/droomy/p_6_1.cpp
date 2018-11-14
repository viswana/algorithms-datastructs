#define WORDMAX 30
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void textformat(size_t linelimit) {
  char word[WORDMAX];
  if (linelimit < WORDMAX) return;
  bool newline = false;
  bool abnewline = false; //absorb newline with space
  size_t wordcnt = 0;
  size_t linecnt = 0;
  char c;
  while ( cin.get(c) ) {
    if (c == '\r') continue;
    else if(c == ' ' || c == '\n') {
      word[wordcnt] = ' ';
      ++wordcnt;
      if (c == '\n') {
	if (wordcnt > 1) abnewline = true;
      }
      if (newline && wordcnt == 1) {
	if (c == '\n') {
	  wordcnt = 0;
	  cout << endl;
	  if (abnewline) {
	    cout << endl;
	    abnewline = false;
	  }
	}
	else {
	  cout << endl;
	}
	linecnt = 0;
      }
      linecnt += wordcnt;
      if (linecnt > linelimit) {
	cout << endl;
	linecnt = wordcnt;
      }
      word[wordcnt] = '\0';
      cout << word;
      wordcnt = 0;
      newline = false;
      if (c == '\n') {
	newline = true;
      }
    }
    else {
      word[wordcnt] = c;
      ++wordcnt;
    }
  }
}

int main() {
  textformat(40);
  return 0;
}
