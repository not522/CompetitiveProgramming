#include "math/mint.hpp"
#include "math/pow.hpp"
#include "string.hpp"
#include "vector.hpp"

int main() {
  int h(in), w(in);
  Vector<String> s(h, in);
  int cnt = 0;
  auto dp1 = Vector<int>::makeVector(h, w);
  auto dp2 = Vector<int>::makeVector(h, w);
  auto dp3 = Vector<int>::makeVector(h, w);
  auto dp4 = Vector<int>::makeVector(h, w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '.') {
        ++cnt;
        dp1[i][j] = 1;
        dp2[i][j] = 1;
        dp3[i][j] = 1;
        dp4[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w - 1; ++j) {
      if (s[i][j + 1] != '#') {
        dp1[i][j + 1] += dp1[i][j];
      }
    }
  }
  for (int i = 0; i < h - 1; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i + 1][j] != '#') {
        dp2[i + 1][j] += dp2[i][j];
      }
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = w - 1; j > 0; --j) {
      if (s[i][j - 1] != '#') {
        dp3[i][j - 1] += dp3[i][j];
      }
    }
  }
  for (int i = h - 1; i > 0; --i) {
    for (int j = 0; j < w; ++j) {
      if (s[i - 1][j] != '#') {
        dp4[i - 1][j] += dp4[i][j];
      }
    }
  }
  Vector<Mint> mem(cnt + 1);
  mem[0] = 1;
  for (int i = 1; i <= cnt; ++i) {
    mem[i] = mem[i - 1] * 2;
  }
  Mint res = mem[cnt] * cnt;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '.') {
        res -= mem[cnt - dp1[i][j] - dp2[i][j] - dp3[i][j] - dp4[i][j] + 3];
      }
    }
  }
  cout << res << endl;
}
