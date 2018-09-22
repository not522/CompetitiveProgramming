#include "template.hpp"

int main() {
  int n, d, x;
  cin >> n >> d >> x;
  vector<int> a(n);
  cin >> a;
  for (int i : a) x += 1 + (d - 1) / i;
  cout << x << endl;
}
