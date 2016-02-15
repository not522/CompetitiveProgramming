#include "vector.hpp"

int main() {
  int n, t;
  cin >> n >> t;
  vector<int> a(n), b(t + 1);
  cin >> a;
  for (int i : a) for (int j = i; j <= t; j += i) ++b[j];
  cout << max(b) << endl;
}
