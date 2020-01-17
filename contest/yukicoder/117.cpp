#include "math/combination.hpp"
#include "math/mint.hpp"

int main() {
  Combination<Mint> comb(2000000);
  int t(in);
  for (int i = 0; i < t; ++i) {
    char c(in);
    in.ignore();
    int n(in);
    in.ignore();
    int k(in);
    in.ignore();
    switch (c) {
    case 'C':
      cout << comb.combination(n, k) << endl;
      break;
    case 'P':
      cout << comb.partial_permutation(n, k) << endl;
      break;
    case 'H':
      cout << comb.repetition(n, k) << endl;
      break;
    }
  }
}
