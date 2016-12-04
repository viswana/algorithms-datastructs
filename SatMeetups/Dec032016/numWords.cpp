/** 
 * \file numWords.cpp
 *
 * Given a sentence with all spaces removed and a dictionary of all legal words.
 * Return the number of words in a valid sentence formed by these letters.
 * Assume you are given an function isValidWord that returns true for a valid word
 * and false otherwise. Return -1 if a valid sentence cannot be formed
 */

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

static unordered_set<string> dict;

bool isValidWord(const string& s) {
  if (dict.count(s)) {
    return true;
  }
  else {
    return false; 
  }
}

int numWords(const string& s) {
  if (s.size() == 0) return 0;
  for (size_t i = 0; i < s.size(); i++) {
    if (isValidWord(s.substr(0, i+1))) {
      int ret;
      if ((ret = numWords(s.substr(i+1, s.size()-1))) != -1) {
        return 1 + ret;
      }
    }
  }
  return -1;
}

int main() {
  dict.insert("a");
  dict.insert("go");
  dict.insert("good");
  dict.insert("odd");
  dict.insert("day");
  dict.insert("today");
  dict.insert("todays");
  dict.insert("meet");
  dict.insert("up");
  dict.insert("was");
  dict.insert("interest");
  dict.insert("interesting");

  cout << numWords("agoodday") << endl; //a good day
  cout << numWords("todaysmeetupwasinteresting") << endl; //todays meet up was interesting
  return 0;
}
