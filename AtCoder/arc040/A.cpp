#include "template.hpp"

int main() {
  int n, r = 0, b = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    r += count(s.begin(), s.end(), 'R');
    b += count(s.begin(), s.end(), 'B');
  }
  if (r > b) cout << "TAKAHASHI" << endl;
  else if (r < b) cout << "AOKI" << endl;
  else cout << "DRAW" << endl;
}
