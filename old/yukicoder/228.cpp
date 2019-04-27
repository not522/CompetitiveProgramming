#include "adjacent_loop.hpp"
#include "vector.hpp"

int main() {
  int a[4][4];
  for (auto& i : a) {
    for (int& j : i) cin >> j;
  }
  bool update = true;
  while (update) {
    update = false;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        if (a[i][j]) continue;
        for (auto k : AdjacentLoop<4>(i, j, 4, 4)) {
          if (a[k.first][k.second] == 4 * i + j + 1) {
            swap(a[k.first][k.second], a[i][j]);
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
