#include "template.hpp"

int main() {
  int n(in), m(in);
  for (int i = 0; i < m; ++i) {
    int p(in), q(in);
    if (n == p) {
      n = q;
    } else if (n == q) {
      n = p;
    }
  }
  cout << n << endl;
}
