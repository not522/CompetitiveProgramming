#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> s(3);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      int k;
      cin >> k;
      s[j] += k;
    }
  }
  cout << (all_of(s.begin(), s.end(), [](int i){return i == 0;}) ? "YES" : "NO") << endl;
}
