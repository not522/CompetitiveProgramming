#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  int m = max(a), b = min(a);
  for (auto i : a) {
    if (abs(m / 2.0 - i) < abs(m / 2.0 - b)) b = i;
  }
  cout << m << " " << b << endl;
}
