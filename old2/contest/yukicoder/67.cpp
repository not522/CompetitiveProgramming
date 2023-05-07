#include "bisection_method.hpp"
#include "math.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> l(n, in);
  int64_t k(in);
  auto f = [&](double x) {
    int64_t sum = 0;
    for (int &i : l) {
      sum += floor(i / x);
    }
    return sum - k + 0.5;
  };
  cout << bisectionMethod(f, inf<int>(), 0);
}
