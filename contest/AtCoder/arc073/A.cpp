#include "template.hpp"

int main() {
  int n, T;
  cin >> n >> T;
  vector<int> t(n);
  cin >> t;
  int s = T;
  for (int i = 1; i < n; ++i) s += min(T, t[i] - t[i - 1]);
  cout << s << endl;
}
