#include "string.hpp"
#include "vector.hpp"

int main() {
  int h(in), w(in);
  (void)w;
  Vector<String> c(h, in);
  for (int i = 0; i < 2 * h; ++i) {
    cout << c[i / 2] << endl;
  }
}
