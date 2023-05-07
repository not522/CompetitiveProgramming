#include "vector.hpp"

int main() {
  Vector<char> c(3, in);
  auto d = c, e = c;
  for (auto &i : d) {
    if (i == '?') {
      i = '1';
    }
  }
  for (auto &i : e) {
    if (i == '?') {
      i = '4';
    }
  }
  if (d.max() == d[1] || d.min() == d[1]) {
    cout << 1;
  }
  if (e.max() == e[1] || e.min() == e[1]) {
    cout << 4;
  }
  cout << endl;
}
