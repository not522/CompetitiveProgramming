#include "template.hpp"

int main() {
  int a(in), b(in), c(in), k(in), s(in), t(in);
  if (s + t >= k) {
    cout << a * s + b * t - c * (s + t) << endl;
  } else {
    cout << a * s + b * t << endl;
  }
}
