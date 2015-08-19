#include "cumulative_sum_2D.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n), y(n), hp(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> hp[i];
  CumulativeSum2D<int, true> sum(1501, 1501);
  for (int i = 0; i < k; ++i) {
    int ax, ay, w, h, d;
    cin >> ax >> ay >> w >> h >> d;
    sum.add(ay + 500, ax + 500, ay + h + 501, ax + w + 501, d);
  }
  int res = 0;
  for (int i = 0; i < n; ++i) res += max(0, hp[i] - sum.value(y[i] + 500, x[i] + 500));
  cout << res << endl;
}
