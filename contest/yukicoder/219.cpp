#include "template.hpp"

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    double a, b;
    cin >> a >> b;
    double res = log10(a) * b;
    int xy = pow(10, fmod(res, 1)) * 10;
    cout << xy / 10 << " " << xy % 10 << " " << (long long)floor(res) << endl;
  }
}
