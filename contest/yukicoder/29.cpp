#include "template.hpp"

int main() {
  int n(in);
  int v[10]{};
  int res = 0, sum = 3 * n;
  for (int i = 0; i < 3 * n; ++i) {
    int a(in);
    --a;
    ++v[a];
    if (v[a] == 2) {
      ++res;
      sum -= 2;
      v[a] = 0;
    }
  }
  cout << res + sum / 4 << endl;
}
