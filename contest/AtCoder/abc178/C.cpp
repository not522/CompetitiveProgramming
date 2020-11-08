#include "math/mint.hpp"
#include "math/pow.hpp"

int main() {
  int n(in);
  cout << pow(Mint(10), n) - 2 * pow(Mint(9), n) + pow(Mint(8), n) << endl;
}
