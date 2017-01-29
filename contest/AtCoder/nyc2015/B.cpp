#include "vector.hpp"

int main() {
  int n, s = 0, res = 0;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  sort(a);
  for (int i : a) {
    if (s < i) {
      s += i;
      ++res;
    }
  }
  cout << res << endl;
}
