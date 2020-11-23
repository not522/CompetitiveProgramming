#include "math/mint.hpp"
#include "math/pow.hpp"
#include "string.hpp"

int main() {
  int n(in);
  String caa(in), cab(in), cba(in), cbb(in);
  if (caa == "A" && cab == "A") {
    cout << 1 << endl;
  } else if (cbb == "B" && cab == "B") {
    cout << 1 << endl;
  } else if (cab == cba) {
    Mint a = 1, b = 1;
    for (int i = 0; i < n - 2; ++i) {
      auto c = a + b;
      a = b;
      b = c;
    }
    cout << a << endl;
  } else {
    cout << pow(Mint(2), max(0, n - 3)) << endl;
  }
}
