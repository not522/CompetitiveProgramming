#include "vector.hpp"
#include "string/join.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> p(n), a(n);
  cin >> p;
  iota(a, 1);
  auto b = a;
  reverse(b);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j < p[i] - 1) b[j] += n - i;
      if (j > p[i] - 1) a[j] += n - i;
    }
  }
  cout << join(a) << endl << join(b) << endl;
}
