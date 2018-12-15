#include "adjacent_loop.hpp"

int main() {
  int n, y, x, h, w;
  cin >> n >> y >> x >> h >> w;
  if (n == 2) {
    for (auto [i, j] : AdjacentLoop<2>(y, x, h, w)) cout << i << " " << j << endl;
  } else if (n == 4) {
    for (auto [i, j] : AdjacentLoop<4>(y, x, h, w)) cout << i << " " << j << endl;
  } else if (n == 5) {
    for (auto [i, j] : AdjacentLoop<5>(y, x, h, w)) cout << i << " " << j << endl;
  } else if (n == 8) {
    for (auto [i, j] : AdjacentLoop<8>(y, x, h, w)) cout << i << " " << j << endl;
  } else {
    for (auto [i, j] : AdjacentLoop<9>(y, x, h, w)) cout << i << " " << j << endl;
  }
}
