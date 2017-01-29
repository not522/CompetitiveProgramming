#include "coordinate_compression.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  auto comp = coordinateCompression(a);
  for (int i : a) cout << comp[i] << endl;
}
