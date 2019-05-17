#include "vector.hpp"

int solve(Vector<int> a, Vector<int> b) {
  while (!b.empty() && b.back() <= a.back()) {
    b.pop_back();
  }
  if (b.empty()) {
    return 1;
  }
  return solve(b, a) + 1;
}

int main() {
  int nw(in);
  Vector<int> w(nw, in);
  w.rsort();
  int nb(in);
  Vector<int> b(nb, in);
  b.rsort();
  cout << max(solve(w, b), solve(b, w)) << endl;
}
