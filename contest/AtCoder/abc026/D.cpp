#include "bisection_method.hpp"

int main() {
  const long double PI = acos(-1);
  int a, b, c;
  cin >> a >> b >> c;
  auto f = [&](long double t){return a * t + b * sin(c * t * PI) - 100;};
  cout << bisectionMethod(f, 0, 1000) << endl;
}
