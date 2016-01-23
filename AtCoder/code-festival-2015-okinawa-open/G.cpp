#include "vector.hpp"
#include "math/mint_combination.hpp"

int main() {
  int a, b, n;
  cin >> a >> b >> n;
  vector<pair<int, int>> p(2 * n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
    p[i + n].first = a - p[i].first;
    p[i + n].second = b - p[i].second;
  }
  p.emplace_back(make_pair(a, b));
  remove_if(p, [&](pair<int, int> k){return k.first < k.second || a - k.first < b - k.second || k.first > a || k.second < 0;});
  sort(p, [](pair<int, int> i, pair<int, int> j){return i.first + i.second < j.first + j.second;});
  Combination<Mint> comb(a + b);
  vector<Mint> dp(p.size());
  int width = a - b + 2;
  auto f = [&](int i, int j, int ii, int jj){
    if (i > ii || j > jj) return Mint(0);
    Mint res = comb.combination(ii - i + jj - j, ii - i);
    for (int i2 = ii + width, j2 = jj - width; j2 >= j; i2 += width, j2 -= width) {
      res += comb.combination(i2 - i + j2 - j, i2 - i);
    }
    for (int i2 = ii - width, j2 = jj + width; i2 >= i; i2 -= width, j2 += width) {
      res += comb.combination(i2 - i + j2 - j, i2 - i);
    }
    for (int i2 = jj + width - 1, j2 = ii - width + 1; j2 >= j; i2 += width, j2 -= width) {
      res -= comb.combination(i2 - i + j2 - j, i2 - i);
    }
    for (int i2 = jj - 1, j2 = ii + 1; i2 >= i; i2 -= width, j2 += width) {
      res -= comb.combination(i2 - i + j2 - j, i2 - i);
    }
    return res;
  };
  for (int i = 0; i < (int)p.size(); ++i) {
    dp[i] += f(0, 0, p[i].first, p[i].second);
    for (int j = 0; j < i; ++j) dp[i] -= dp[j] * f(p[j].first, p[j].second, p[i].first, p[i].second);
  }
  cout << dp.back() << endl;
}
