#include "template.hpp"

int main() {
  int n;
  cin >> n;
  string s = bitset<32>(n).to_string();
  s = s.substr(s.find('1'));
  string r = s;
  reverse(r.begin(), r.end());
  cout << (s == r ? "Yes" : "No") << endl;
}
