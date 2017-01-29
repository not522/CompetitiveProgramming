#include "template.hpp"

int main() {
  int res = 0;
  for (int i = 0; i < 12; ++i) {
    string s;
    cin >> s;
    if (s.find("r") != string::npos) ++res;
  }
  cout << res << endl;
}
