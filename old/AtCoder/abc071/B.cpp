#include "template.hpp"

int main() {
  string s;
  cin >> s;
  vector<int> v(26);
  for (char c : s) ++v[c - 'a'];
  for (int i = 0; i < 26; ++i) {
    if (v[i] == 0) {
      cout << char(i + 'a') << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}
