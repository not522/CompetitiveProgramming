#include "template.hpp"

int main() {
  string s;
  cin >> s;
  for (char c = 'A'; c <= 'F'; ++c) cout << count(s.begin(), s.end(), c) << (c != 'F' ? ' ' : '\n');
}
