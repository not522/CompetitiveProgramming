#include "template.hpp"

int main() {
  string s;
  cin >> s;
  cout << (s.substr(0, 4) == "YAKI" ? "Yes" : "No") << endl;
}
