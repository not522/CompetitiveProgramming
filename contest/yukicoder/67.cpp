#include "bisection_method.hpp"
#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  cin >> l;
  long long k;
  cin >> k;
  auto f = [&](double x){
    long long sum = 0;
    for (int& i : l) sum += floor(i / x);
    return sum - k + 0.5;
  };
  cout << bisectionMethod(f, numeric_limits<int>::max(), 0);
}
