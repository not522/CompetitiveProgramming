#include "math/mint.hpp"

int main() {
  Mint a, b, c;
  cin >> a >> b >> c;
  cout << (b * c - a * c) / (a * c - b * c + a * b) << " ";
  cout << (b * c - a * b) / (a * c - b * c + a * b) << endl;
}
