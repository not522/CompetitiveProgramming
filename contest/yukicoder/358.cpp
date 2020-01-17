#include "vector.hpp"

int main() {
  Vector<int> a(3, in);
  if (copy(a).sort().unique().size() != 3) {
    cout << 0 << endl;
  } else if ((a[0] < a[1]) != (a[1] < a[2])) {
    cout << "INF" << endl;
  } else {
    int res = 0;
    for (int i = 1; i <= 1000; ++i) {
      Vector<int> b(3);
      for (int j = 0; j < 3; ++j) {
        b[j] = a[j] % i;
      }
      if (copy(b).sort().unique().size() == 3 &&
          (b[0] < b[1]) != (b[1] < b[2])) {
        ++res;
      }
    }
    cout << res << endl;
  }
}
