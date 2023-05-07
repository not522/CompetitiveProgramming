#include "string.hpp"

int main() {
  int n(in), m(in);
  Vector<int> submit(n);
  Vector<bool> solved(n);
  int ac = 0, penalty = 0;
  for (int i = 0; i < m; ++i) {
    int p(in);
    --p;
    String s(in);
    if (s == "AC" and !solved[p]) {
      ++ac;
      penalty += submit[p];
      solved[p] = true;
    }
    ++submit[p];
  }
  cout << ac << " " << penalty << endl;
}
