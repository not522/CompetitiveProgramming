#include "vector.hpp"

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> c(h);
  cin >> c;
  for (int i = 0; i < 2 * h; ++i) cout << c[i / 2] << endl;
}
