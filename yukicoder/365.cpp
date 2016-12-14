#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  reverse(a);
  for (int i : a) if (i == n) --n;
  cout << n << endl;
}
