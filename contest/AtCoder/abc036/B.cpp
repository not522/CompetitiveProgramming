#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  cin >> s;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << s[n - 1 - j][i];
    }
    cout << endl;
  }
}
