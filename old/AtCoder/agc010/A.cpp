#include "vector.hpp"

int main() {
  int n, c = 0;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  for (int i : a) c ^= i % 2;
  cout << (c ? "NO" : "YES") << endl;
}
