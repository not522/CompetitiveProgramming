#include "dp/digit_dp.hpp"

class PermittedNumber : public DigitDP<long long, array<long long, 2>> {
protected:
  void step(int n) {
    curr[0] = prev[0] * 8;
    if (n <= 4) curr[0] += prev[1] * n;
    else curr[0] += prev[1] * (n - 1);
    if (n != 4 && n != 9) curr[1] = prev[1];
    else curr[1] = 0;
  }

  long long result() {return curr[0] + curr[1];}

public:
  PermittedNumber(long long num) : DigitDP<long long, array<long long, 2>>(num) {curr = {0, 1};}
};

long long solve(long long n) {
  PermittedNumber permittedNumber(n);
  return permittedNumber.solve();
}

int main() {
  long long a, b;
  cin >> a >> b;
  cout << (b - a + 1) - (solve(b) - solve(a - 1)) << endl;
}
