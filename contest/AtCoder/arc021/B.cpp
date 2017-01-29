#include "vector.hpp"

int main() {
  int l;
  cin >> l;
  vector<int> a(l), b(l);
  cin >> b;
  for (int i = 0; i < l - 1; ++i) a[i + 1] = a[i] ^ b[i];
  if (b.back() == (a[0] ^ a.back())) cout << a;
  else cout << -1 << endl;
}
