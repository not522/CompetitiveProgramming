#include "vector.hpp"

int main() {
  int n, t, r = 0, d = 0, mn = numeric_limits<int>::max();
  cin >> n >> t;
  vector<int> a(n);
  cin >> a;
  for (int i : a) {
    if (i - mn > d) {
      r = 1;
      d = i - mn;
    } else if (i - mn == d) {
      ++r;
    } else if (i < mn) {
      mn = i;
    }
  }
  cout << r << endl;
}
