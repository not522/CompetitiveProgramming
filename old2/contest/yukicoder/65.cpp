#include "dp/memoized_recursion.hpp"

class Dice : public MemoizedRecursion<double, int> {
private:
  double eval(int v) {
    double res = 1;
    for (int i = 1; i <= 6; ++i) {
      if (v - i > 0) {
        res += solve(v - i) / 6;
      }
    }
    return res;
  }
};

int main() {
  int k(in);
  Dice dice;
  cout << dice.solve(k) << endl;
}
