#include "math/mint.hpp"
#include "string.hpp"

int main() {
  [[maybe_unused]] int n(in);
  String s(in);
  Vector<Mint> cnt(26, 1);
  for (char c : s) {
    ++cnt[c - 'a'];
  }
  cout << cnt.accumulate(Mint(1), std::multiplies<Mint>()) - 1 << endl;
}
