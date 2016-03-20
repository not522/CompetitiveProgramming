#include "vector.hpp"

int main() {
  string s;
  vector<int> a(4);
  cin >> s >> a;
  for (int i = 0; i <= (int)s.size(); ++i) {
    if (in(a, i)) cout << "\"";
    if (i < (int)s.size()) cout << s[i];
  }
  cout << endl;
}
