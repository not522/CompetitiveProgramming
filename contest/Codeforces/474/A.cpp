#include "template.hpp"

int main() {
  unordered_map<char, char> right, left;
  string key[]{"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
  for (auto& s : key) {
    for (int i = 0; i < (int)s.size() - 1; ++i) {
      right[s[i]] = s[i + 1];
      left[s[i + 1]] = s[i];
    }
  }
  string a, s;
  cin >> a >> s;
  for (char c : s) cout << (a == "R" ? left[c] : right[c]);
  cout << endl;
}
