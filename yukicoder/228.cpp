#include "math/inversion_number.hpp"

int main() {
  int a[4][4];
  for (auto& i : a) {
    for (int& j : i) cin >> j;
  }
  vector<int> v;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      int k = a[i][i % 2 ? j : 3 - j];
      if (k) v.emplace_back(k);
    }
  }
  if (inversion_number(v) % 2) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (a[i][j] == 0) continue;
      int d = a[i][j] - (i * 4 + j + 1);
      if (d != -4 && d != -1 && d != 0 && d != 1 && d != 4) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}
