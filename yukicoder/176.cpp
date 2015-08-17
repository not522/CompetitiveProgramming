#include "math/basic.hpp"

int main() {
  int a, b, t;
  cin >> a >> b >> t;
  int aa = 0, bb = ceil(t, b), res = bb * b;
  for (int i = 0; i < a && bb; ++i) {
    --bb;
    aa = ceil(t - bb * b, a);
    res = min(res, aa * a + bb * b);
  }
  cout << res << endl;
}
