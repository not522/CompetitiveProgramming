#include "math/mint.hpp"
#include "math/pow.hpp"
#include "string.hpp"

int main() {
  String n(in), m(in);
  m = "0" + m;
  Mint::setMod(10);
  Mint nn = stoi(n.substr(n.size() - 1));
  int mm = stoi(m.substr(m.size() - 2));
  if (m.size() != 2u && mm == 0) {
    mm = 100;
  }
  cout << pow(nn, mm) << endl;
}
