#include "bisection_method.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  for (int& i : l) cin >> i;
  long long k;
  cin >> k;
  auto f = [&](double x){
    long long sum = 0;
    for (int& i : l) sum += floor(i / x);
    return sum - k + 0.5;
  };
  cout << fixed << setprecision(15) << bisectionMethod(f, numeric_limits<int>::max(), 0);
}
