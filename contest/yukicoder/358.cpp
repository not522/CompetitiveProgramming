#include "vector.hpp"

int main() {
  vector<int> a(3);
  cin >> a;
  if (set<int>(a.begin(), a.end()).size() != 3u) {
    cout << 0 << endl;
  } else if ((a[0] < a[1]) != (a[1] < a[2])) {
    cout << "INF" << endl;
  } else {
    int res = 0;
    for (int i = 1; i <= 1000; ++i) {
      vector<int> b(3);
      for (int j = 0; j < 3; ++j) {
        b[j] = a[j] % i;
      }
      if (set<int>(b.begin(), b.end()).size() == 3u && (b[0] < b[1]) != (b[1] < b[2])) {
        ++res;
      }
    }
    cout << res << endl;
  }
}
