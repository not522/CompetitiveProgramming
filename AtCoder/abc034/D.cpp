#include "bisection_method.hpp"
#include "vector.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> w(n), p(n);
  for (int i = 0; i < n; ++i) cin >> w[i] >> p[i];
  auto f = [&](long double q){
    vector<long double> v(n);
    for (int i = 0; i < n; ++i) v[i] = (q - p[i]) * w[i];
    nth_element(v, k);
    v.resize(k);
    return accumulate(v);
  };
  cout << bisectionMethod(f) << endl;
}
