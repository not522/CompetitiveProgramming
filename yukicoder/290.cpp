#include "template.hpp"

int main() {
  int n;
  string s;
  cin >> n >> s;
  cout << (n >= 4 || s.find("00") != string::npos || s.find("11") != string::npos ? "YES" : "NO") << endl;
}
