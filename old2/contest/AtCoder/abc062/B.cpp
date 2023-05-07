#include "string.hpp"
#include "vector.hpp"

int main() {
  int h(in), w(in);
  Vector<String> a(h, in);
  cout << String(w + 2, '#') << endl;
  for (int i = 0; i < h; ++i) {
    cout << '#' << a[i] << '#' << endl;
  }
  cout << String(w + 2, '#') << endl;
}
