#include "template.hpp"

int main() {
  int n;
  string s;
  cin >> n >> s;
  int cnt = 0;
  for (int i = 0; i < 2 * n - 1; ++i) {
    if (s[i] != s[i + 1]) {
      ++cnt;
      ++i;
    }
  }
  cout << n - cnt << endl;
}
