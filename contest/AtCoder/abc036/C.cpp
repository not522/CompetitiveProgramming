#include "coordinate_compression.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in);
  auto comp = coordinateCompression(a);
  for (int i : a) {
    cout << comp[i] << endl;
  }
}
