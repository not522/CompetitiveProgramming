#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> s[i] >> p[i];
  int sum = accumulate(p);
  for (int i = 0; i < n; ++i) {
    if (sum < p[i] * 2) {
      cout << s[i] << endl;
      return 0;
    }
  }
  cout << "atcoder" << endl;
}
