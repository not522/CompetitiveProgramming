#include "template.hpp"

int main() {
  int n, m = 0;
  cin >> n;
  for (int i = 1; ; ++i) {
    string s = to_string(i);
    if (set<char>(s.begin(), s.end()).size() != 1u) continue;
    ++m;
    if (n > m) continue;
    cout << i << endl;
    break;
  }
}
