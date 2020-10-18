#include "math/mint.hpp"

int main() {
  int n(in);
  Vector<Mint> a(n, in);
  auto a_sum = a.accumulate(), aa_sum = (a * a).accumulate();
  cout << (a_sum * a_sum - aa_sum) / 2 << endl;
}
