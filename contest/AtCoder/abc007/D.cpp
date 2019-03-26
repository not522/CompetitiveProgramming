#include "dp/digit_dp.hpp"

class PermittedNumber : public DigitDP<int64_t, Vector<int64_t>> {
protected:
  void step(int n) {
    curr[0] = prev[0] * 8;
    if (n <= 4) {
      curr[0] += prev[1] * n;
    } else {
      curr[0] += prev[1] * (n - 1);
    }
    if (n != 4 && n != 9) {
      curr[1] = prev[1];
    } else {
      curr[1] = 0;
    }
  }

  int64_t result() { return curr[0] + curr[1]; }

public:
  PermittedNumber(int64_t num) : DigitDP<int64_t, Vector<int64_t>>(num) {
    curr = {{0, 1}};
  }
};

int64_t solve(int64_t n) {
  PermittedNumber permittedNumber(n);
  return permittedNumber.solve();
}

int main() {
  int64_t a(in), b(in);
  cout << (b - a + 1) - (solve(b) - solve(a - 1)) << endl;
}
