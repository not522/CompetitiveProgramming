#include "template.hpp"

int main() {
  constexpr int N = 600;
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  cin >> s;
  vector<vector<bool>> v(N, vector<bool>(N));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      v[i - j + w][i + j] = (s[i][j] == '#');
    }
  }
  int64_t res = 0;
  for (int x = 0; x < 4; ++x) {
    for (int d = 2; d < N; d += 2) {
      for (int i = 0; i + d < N; ++i) {
        int c = 0;
        for (int j = 0; j < d; ++j) c += v[i + d][j];
        for (int j = 0; j + d < 600; ++j) {
          if (v[i][j] && v[i][j + d]) res += c;
          c += v[i + d][j + d];
          c -= v[i + d][j];
        }
      }
    }
    auto u = v;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        v[i][j] = u[N - j - 1][i];
      }
    }
  }
  cout << res << endl;
}
