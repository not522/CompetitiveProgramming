#include "template.hpp"

int main() {
  string s[3];
  for (auto& i : s) cin >> i;
  map<char, int> m[3];
  for (int i = 0; i < 3; ++i) {
    for (char c : s[i]) ++m[i][c];
  }
  int a = 0, b = 0;
  for (const auto& i : m[2]) {
    char c = i.first;
    int v = i.second;
    if (m[0][c] + m[1][c] < v) {
      cout << "NO" << endl;
      return 0;
    }
    a += max(0, v - m[1][c]);
    b += max(0, v - m[0][c]);
  }
  cout << (a <= int(s[0].size()) / 2 && b <= int(s[0].size()) / 2 ? "YES" : "NO") << endl;
}
