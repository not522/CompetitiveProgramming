#include "math/combination.hpp"
#include "math/mint.hpp"

int main() {
  Combination<Mint> comb(2000000);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    char c;
    int n, k;
    cin >> c;
    cin.ignore();
    cin >> n;
    cin.ignore();
    cin >> k;
    cin.ignore();
    switch (c) {
    case 'C': cout << comb.combination(n, k) << endl; break;
    case 'P': cout << comb.partial_permutation(n, k) << endl; break;
    case 'H': cout << comb.repetition(n, k) << endl; break;
    }
  }
}
