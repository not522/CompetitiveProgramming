#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int res = 0;
  for (uint i = 0; i < s.size() - 1; ++i) {
    if (s.substr(i, 2) == "BW" || s.substr(i, 2) == "WB") ++res;
  }
  cout << res << endl;
}
