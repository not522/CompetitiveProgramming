#include "string.hpp"
#include "vector.hpp"

int main() {
  int n(in), q(in);
  String s(in);
  Vector<int> c(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    if (s.substr(i, 2) == "AC") {
      c[i + 2] = c[i + 1] + 1;
    } else {
      c[i + 2] = c[i + 1];
    }
  }
  for (int i = 0; i < q; ++i) {
    int l(in), r(in);
    cout << c[r] - c[l] << endl;
  }
}
