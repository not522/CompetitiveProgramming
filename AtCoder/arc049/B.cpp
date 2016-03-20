#include "bisection_method.hpp"
#include "minmax.hpp"

int main() {
  int n;
  cin >> n;
  vector<double> x(n), y(n), c(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> c[i];
  auto f = [&](long double t){
    long double top = 1e9, bottom = -1e9, right = 1e9, left = -1e9;
    for (int i = 0; i < n; ++i) {
      chmin(top, x[i] + t / c[i]);
      chmax(bottom, x[i] - t / c[i]);
      chmin(right, y[i] + t / c[i]);
      chmax(left, y[i] - t / c[i]);
    }
    return min(top - bottom, right - left);
  };
  cout << bisectionMethod(f) << endl;
}
