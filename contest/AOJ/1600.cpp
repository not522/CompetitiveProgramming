#include "vector.hpp"

int main() {
  while (true) {
    int m, nmin, nmax, r = 0, res = -1;
    cin >> m >> nmin >> nmax;
    if (m == 0 && nmin == 0 && nmax == 0) break;
    vector<int> p(m);
    cin >> p;
    for (int i = nmax; i >= nmin; --i) {
      if (chmax(r, p[i - 1] - p[i])) res = i;
    }
    cout << res << endl;
  }
}
