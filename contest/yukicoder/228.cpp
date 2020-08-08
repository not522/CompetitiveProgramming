#include "adjacent_loop.hpp"
#include "vector.hpp"

int main() {
  auto a = Vector<int>::makeVector(in, 4, 4);
  bool update = true;
  while (update) {
    update = false;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        if (a[i][j]) {
          continue;
        }
        for (auto [ii, jj] : AdjacentLoop<4>(i, j, 4, 4)) {
          if (a[ii][jj] == 4 * i + j + 1) {
            swap(a[ii][jj], a[i][j]);
            update = true;
            break;
          }
        }
      }
    }
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (a[i][j] && a[i][j] != 4 * i + j + 1) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}
