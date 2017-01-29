#include "template.hpp"

int main() {
  string s;
  cin >> s;
  if (all_of(s.begin() + 1, s.end(), [](char c){return isupper(c);})) {
    transform(s.begin(), s.end(), s.begin(), [](char c){return c ^ 32;});
  }
  cout << s << endl;
}
