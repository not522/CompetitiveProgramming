#include "vector.hpp"

int main() {
  vector<int> d(7);
  cin >> d;
  sort(d);
  do {
    bool ok = true;
    for (int i = 2; i < 7; ++i) {
      if (d[i - 2] >= d[i]) ok = false;
      if (d[i - 2] == d[i - 1] || d[i - 1] == d[i]) ok = false;
      if ((d[i - 1] < d[i - 2]) == (d[i] < d[i - 1])) ok = false;
    }
    if (ok) {
      cout << "YES" << endl;
      return 0;
    }
  } while (next_permutation(d));
  cout << "NO" << endl;
}
