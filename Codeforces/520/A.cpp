#include "vector.hpp"

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<bool> used(26);
  for (char c : s) used[tolower(c) - 'a'] = true;
  cout << (in(used, false) ? "NO" : "YES") << endl;
}
