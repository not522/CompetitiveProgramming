#include "vector.hpp"

int main() {
  int64_t n(in);
  if (n < 4) {
    cout << "impossible" << endl;
  } else if (n % 2 == 0) {
    cout << n / 2 << endl;
    for (int i = 0; i < n / 2; ++i) {
      cout << 2 << " " << 2 * i + 1 << " " << 2 * n - 2 * i - 1 << endl;
    }
  } else {
    for (int64_t k = 2; k * k <= n; ++k) {
      if (n % k) {
        continue;
      }
      auto v = Vector<int>::makeVector(k, n / k);
      for (int i = 0; i < n / k; ++i) {
        v.back()[i] = k / 2;
      }
      for (int i = 0; i < k; ++i) {
        v[i].back() = k / 2;
      }
      for (int64_t i = 0; i < k / 2; ++i) {
        for (int64_t j = 0; j < n / k / 2; ++j) {
          v[2 * i][2 * j] = i;
          v[2 * i][2 * j + 1] = k - i - 1;
          v[2 * i + 1][2 * j] = k - i - 1;
          v[2 * i + 1][2 * j + 1] = i;
        }
      }
      for (int i = 0; 4 * i + 4 < k; ++i) {
        swap(v[4 * i][4 * i], v[4 * i].back());
        swap(v[4 * i + 1][4 * i + 2], v[4 * i + 1].back());
        swap(v[4 * i + 2][4 * i + 1], v[4 * i + 2].back());
        swap(v[4 * i + 3][4 * i + 3], v[4 * i + 3].back());
        v.back()[4 * i] = v[4 * i].back();
        v.back()[4 * i + 2] = v[4 * i + 1].back();
        v.back()[4 * i + 1] = v[4 * i + 2].back();
        v.back()[4 * i + 3] = v[4 * i + 3].back();
      }
      if ((k - 1) % 4 == 2) {
        swap(v[k - 3][k - 3], v[k - 3].back());
        v.back()[k - 3] = v[k - 3].back();
        v.back().back() = v[k - 2][k - 3];
      }
      cout << k << endl;
      for (int i = 0; i < k; ++i) {
        cout << n / k;
        for (int j = 0; j < n / k; ++j) {
          cout << " " << 2 * v[i][j] + 2 * j * k + 1;
        }
        cout << endl;
      }
      return 0;
    }
    cout << "impossible" << endl;
  }
}
