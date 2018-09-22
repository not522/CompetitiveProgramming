#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  cin >> s;
  if (kinds(s) != n) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 1; i < n; ++i) {
    if (s[i - 1].back() != s[i][0]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
