#include "template.hpp"

const int INF = numeric_limits<int>::max();
int d;

void magic(int& n, int& res, int t = 1) {
  n -= d * t;
  if (n < 0) n = 0;
  res += t;
}

bool isKadomatsu(int h1, int h2, int h3) {
  return h1 != h2 && h1 != h3 && h2 != h3 && ((h2 > h1 && h2 > h3) || (h2 < h1 && h2 < h3));
}

int solve1(int h1, int h2, int h3) {
  if (h2 == 0) return INF;
  int res = 0;
  if (h1 >= h2) magic(h1, res, (h1 - h2) / d + 1);
  if (h3 >= h2) magic(h3, res, (h3 - h2) / d + 1);
  if (h1 == h3) magic(h1, res);
  if (h1 == h3) return INF;
  return res;
}

int solve2(int h1, int h2, int h3) {
  int res = 0;
  if (h1 == h3) magic(h1, res);
  if (h1 == 0 || h3 == 0) return INF;
  if (min(h1, h3) <= h2) magic(h2, res, (h2 - min(h1, h3)) / d + 1);
  return res;
}

int main() {
  int h1, h2, h3;
  cin >> d >> h1 >> h2 >> h3;
  if (isKadomatsu(h1, h2, h3)) {
    cout << 0 << endl;
  } else if (d == 0) {
    cout << -1 << endl;
  } else {
    int res = min(solve1(h1, h2, h3), solve2(h1, h2, h3));
    cout << (res == INF ? -1 : res) << endl;
  }
}
