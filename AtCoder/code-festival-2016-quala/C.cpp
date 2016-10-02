#include "template.hpp"

int main() {
  string s;
  int k;
  cin >> s >> k;
  for (char& c : s) {
    if (c != 'a' && 'z' + 1 - c <= k) {
      k -= 'z' + 1 - c;
      c = 'a';
    }
  }
  s.back() += k % 26;
  cout << s << endl;
}
