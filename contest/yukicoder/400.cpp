#include "template.hpp"

int main() {
  string s;
  cin >> s;
  for_each(s.rbegin(), s.rend(), [](char c){cout << char(c ^ '<' ^ '>');});
  cout << endl;
}
