#include "container/power_set.hpp"
#include "string.hpp"

int main() {
  int h(in), w(in), k(in), res = 0;
  Vector<String> c(h, in);
  for (auto bit_i : powerSet(h)) {
    for (auto bit_j : powerSet(w)) {
      int cnt = 0;
      for (auto i : bit_i) {
        for (auto j : bit_j) {
          if (c[i][j] == '#') {
            ++cnt;
          }
        }
      }
      if (cnt == k) {
        ++res;
      }
    }
  }
  cout << res << endl;
}
