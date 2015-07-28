#include "math/mint.hpp"
#include "math/pow.hpp"
#include "string/to_integer.hpp"

int main() {
  string n, m;
  cin >> n >> m;
  m = "0" + m;
  Mint::setMod(10);
  Mint nn = toInteger<int>(n.substr(n.size() - 1));
  int mm = toInteger<int>(m.substr(m.size() - 2));
  if (m.size() != 2u && mm == 0) mm = 100;
  cout << pow(nn, mm) << endl;
}
