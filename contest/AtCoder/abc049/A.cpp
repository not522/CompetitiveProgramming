#include "template.hpp"

int main() {
  char c;
  cin >> c;
  cout << (string("aeiou").find(c) != string::npos ? "vowel" : "consonant") << endl;
}
