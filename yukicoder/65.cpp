#include "dp/memoized_recursion.hpp"

class Dice : public MemoizedRecursion<double> {
private:
  double eval(int v) {
    double res = 1;
    for (int i = 1; i <= 6; ++i) {
      if (v - i > 0) res += solve(v - i) / 6;
    }
    return res;
  }
};

int main() {
  int k;
  cin >> k;
  Dice dice;
  cout << fixed << setprecision(15) << dice.solve(k) << endl;
}
