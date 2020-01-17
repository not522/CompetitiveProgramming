#include "vector.hpp"

int main() {
  setBoolName("YES", "NO");
  Vector<int> d(7, in);
  d.sort();
  do {
    bool ok = true;
    for (int i = 2; i < 7; ++i) {
      if (d[i - 2] >= d[i]) {
        ok = false;
      }
      if (d[i - 2] == d[i - 1] || d[i - 1] == d[i]) {
        ok = false;
      }
      if ((d[i - 1] < d[i - 2]) == (d[i] < d[i - 1])) {
        ok = false;
      }
    }
    if (ok) {
      cout << true << endl;
      return 0;
    }
  } while (d.next_permutation());
  cout << false << endl;
}
