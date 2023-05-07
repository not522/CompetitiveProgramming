#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> c(n, in);
  double res = 0;
  for (int i : c) {
    int cnt = 0;
    for (int j : c) {
      if (i % j == 0) {
        ++cnt;
      }
    }
    res += (cnt + 1) / 2 / double(cnt);
  }
  cout << res << endl;
}
