#include "vector.hpp"

int main() {
  string s;
  vector<unsigned> a(4);
  cin >> s >> a;
  for (unsigned i = 0; i <= s.size(); ++i) {
    if (in(a, i)) cout << "\"";
    if (i < s.size()) cout << s[i];
  }
  cout << endl;
}
