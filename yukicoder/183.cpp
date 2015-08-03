#include "dp/knapsack.hpp"

struct Weight {
  int val;

  Weight() {}

  Weight(int val) : val(val) {}

  Weight operator+(const Weight& weight) const {
    return Weight(val ^ weight.val);
  }

  operator int() const {
    return val;
  }
};

int main() {
  int n;
  cin >> n;
  vector<Weight> a(n);
  for (auto& i : a) {
    int w;
    cin >> w;
    i = w;
  }
  auto v = knapsack_fill(Weight(1 << 15), a);
  cout << count(v.begin(), v.end(), true) << endl;
}
