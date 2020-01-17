#include "math.hpp"

int main() {
  int a(in), b(in), t(in);
  int aa = 0, bb = ceil(t, b), res = bb * b;
  for (int i = 0; i < a && bb; ++i) {
    --bb;
    aa = ceil(t - bb * b, a);
    chmin(res, aa * a + bb * b);
  }
  cout << res << endl;
}
