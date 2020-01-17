#include "vector.hpp"

int main() {
  setBoolName("YES", "NO");
  int n(in);
  Vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    int g(in), d(in);
    v[i] = g - 30000 * d;
  }
  if (3000000 <= v.max() * 6) {
    cout << true << endl;
    for (int i = 0; i < 6; ++i) {
      cout << v.argmax() + 1 << endl;
    }
  } else {
    cout << false << endl;
  }
}
