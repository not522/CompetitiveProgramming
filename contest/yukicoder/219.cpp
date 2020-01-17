#include "math.hpp"

int main() {
  int n(in);
  for (int i = 0; i < n; ++i) {
    double a(in), b(in);
    double res = log10(a) * b;
    int xy = pow(10, fmod(res, 1)) * 10;
    cout << xy / 10 << " " << xy % 10 << " " << int64_t(floor(res)) << endl;
  }
}
