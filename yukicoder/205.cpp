#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (auto& i : s) {
    cin >> i;
    i += 'z' + 1;
  }
  string t;
  while (!s.empty()) {
    sort(s.begin(), s.end());
    t += s[0][0];
    s[0] = s[0].substr(1);
    if (s[0].size() == 1u) {
      s[0] = s.back();
      s.pop_back();
    }
  }
  cout << t << endl;
}
