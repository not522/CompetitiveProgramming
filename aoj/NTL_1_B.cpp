#include "mint.hpp"

int main() {
  Mint::setMod(1000000007);
  Mint m;
  int n;
  cin >> m >> n;
  cout << pow(m, n) << endl;
}
