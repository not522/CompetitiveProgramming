#include "dp/knapsack.hpp"

struct Weight {
  int val;

  Weight() {}

  Weight(int val) : val(val) {}

  Weight(Input &in) : val(in) {}

  Weight operator+(const Weight &weight) const {
    return Weight(val ^ weight.val);
  }

  operator int() const { return val; }
};

int main() {
  int n(in);
  Vector<Weight> a(n, in);
  auto v = knapsackFill(Weight(1 << 15), a);
  cout << count(v.begin(), v.end(), true) << endl;
}
