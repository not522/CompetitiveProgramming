#include "string.hpp"

int main() {
  String s(in);
  cout << (s.isPalindrome() && s.substr(0, s.size() / 2).isPalindrome() &&
           s.substr(s.size() / 2 + 1).isPalindrome())
       << endl;
}
