#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  cin >> v;
  int mx = v[0], mn = v[0], res = 0;
  for (int i : v) {
    if (i > mx) {
      ++res;
      mx = i;
    }
    if (i < mn) {
      ++res;
      mn = i;
    }
  }
  cout << res << endl;
}
