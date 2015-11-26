#include "bisection_method.hpp"
#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  cin >> l;
  auto f = [&](double x){
    long long sum = 0;
    for (int& i : l) sum += floor(i / x);
    return sum - 500000 + 0.5;
  };
  auto mx =  bisectionMethod(f, numeric_limits<int>::max(), 0);
  vector<long double> res;
  for (const int& i : l) {
    for (int j = 1; ; ++j) {
      long double d = (long double)i / j;
      if (d < mx - 1e-9) break;
      res.emplace_back(d);
    }
  }
  rsort(res);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int k;
    cin >> k;
    cout << fixed << setprecision(15) << res[k - 1] << endl;
  }
}
