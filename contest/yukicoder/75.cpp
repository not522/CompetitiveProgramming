#include "vector.hpp"

int main() {
  int k(in);
  Vector<double> dp1(k + 6), dp2(k + 6);
  dp1[0] = 1;
  for (int i = 1; i < k + 6; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (i - j < 0 || k <= i - j) {
        continue;
      }
      dp1[i] += dp1[i - j] / 6;
      dp2[i] += dp1[i - j] / 6 * (dp2[i - j] + 1);
    }
    dp2[i] /= dp1[i];
  }
  double t = 0;
  for (int i = k + 1; i < k + 6; ++i) {
    t += dp1[i] * dp2[i];
  }
  t /= accumulate(dp1.begin() + k + 1, dp1.end(), 0.);
  cout << dp2[k] + t * (1 - dp1[k]) / dp1[k] << endl;
}
