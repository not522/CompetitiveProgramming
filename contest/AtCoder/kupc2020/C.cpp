#include "set.hpp"
#include "vector.hpp"

int main() {
  auto v = Vector<int>::makeVector(13, 13);
  Set<Tuple<int, int>> s;
  for (int i = 1; i < 13; ++i) {
    v[0][i] = i;
    s.emplace(i - 1, i);
  }
  for (int i = 1; i < 13; ++i) {
    v[i][0] = 26 - i;
    s.emplace(v[i - 1][0], v[i][0]);
  }
  for (int i = 1; i < 13; ++i) {
    for (int j = 1; j < 13; ++j) {
      for (int k = 0; k < 26; ++k) {
        if (!s.contains(makeTuple(v[i - 1][j], k)) &&
            !s.contains(makeTuple(v[i][j - 1], k))) {
          v[i][j] = k;
          s.emplace(v[i - 1][j], k);
          s.emplace(v[i][j - 1], k);
          break;
        }
      }
    }
  }
  cout << 13 << endl;
  for (int i = 0; i < 13; ++i) {
    for (int j = 0; j < 13; ++j) {
      cout << char(v[i][j] + 'a');
    }
    cout << endl;
  }
}
