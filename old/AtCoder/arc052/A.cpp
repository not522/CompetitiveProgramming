#include "template.hpp"

int main() {
  string s;
  cin >> s;
  for (char c : s) {
    if (isdigit(c)) cout << c;
  }
  cout << endl;
}
