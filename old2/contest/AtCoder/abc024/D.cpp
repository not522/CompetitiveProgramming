#include "math/mint.hpp"

int main() {
  Mint a(in), b(in), c(in);
  cout << (b * c - a * c) / (a * c - b * c + a * b) << " "
       << (b * c - a * b) / (a * c - b * c + a * b) << endl;
}
