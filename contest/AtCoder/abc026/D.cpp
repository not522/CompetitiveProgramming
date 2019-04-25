#include "bisection_method.hpp"
#include "math/basic.hpp"

int main() {
  int a(in), b(in), c(in);
  auto f = [&](long double t) { return a * t + b * sin(c * t * pi()) - 100; };
  cout << bisectionMethod(f, 0, 1000) << endl;
}
