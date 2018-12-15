#include "string/join.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  deque<int> b;
  cin >> a;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) b.emplace_back(a[i]);
    else b.emplace_front(a[i]);
  }
  if (n % 2) reverse(b.begin(), b.end());
  cout << join(b) << endl;
}
