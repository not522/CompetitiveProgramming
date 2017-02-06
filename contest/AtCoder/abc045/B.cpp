#include "template.hpp"

int main() {
  string s[3];
  int t = 0;
  for (auto& i : s) {
    cin >> i;
    reverse(i.begin(), i.end());
  }
  while (true) {
    if (s[t].empty()) {
      cout << char(t + 'A') << endl;
      return 0;
    }
    int p = s[t].back() - 'a';
    s[t].pop_back();
    t = p;
  }
}
