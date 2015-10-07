#include "template.hpp"

int main() {
  string s;
  cin >> s;
  cout << (s.find(string(7, '0')) != string::npos || s.find(string(7, '1')) != string::npos ? "YES" : "NO") << endl;
}
