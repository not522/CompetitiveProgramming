#include "template.hpp"

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < int(s.size()) - 1; ++i) {
    if (s.substr(i, 2) == "AC") {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
