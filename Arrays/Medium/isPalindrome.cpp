#include <iostream>
#include <cstring>
using namespace std;

//O(n) time and O(1) space
bool isPalindrome(char* input) {
  size_t len = strlen(input);
  for (size_t i = 0; i < len/2; i++) 
    if (input[i] != input[len-1-i])
      return false;
  return true;
}

int main() {
  char input[] = "able was I ere I saw elba";
  cout << "\"" << input << "\"" << ((isPalindrome(input)) ? " is a palindrome" : " is not a palindrome") << endl;
  return 0;
}
