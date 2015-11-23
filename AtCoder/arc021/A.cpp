#include "template.hpp"

int main() {
  array<array<int, 4>, 4> a;
  for (auto& i : a) {
    for (int& j : i) cin >> j;
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (a[i][j] == a[i + 1][j]) {
        cout << "CONTINUE" << endl;
        return 0;
      }
    }
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (a[i][j] == a[i][j + 1]) {
        cout << "CONTINUE" << endl;
        return 0;
      }
    }
  }
  cout << "GAMEOVER" << endl;
}
