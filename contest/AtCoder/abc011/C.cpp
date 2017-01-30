#include "dp/memoized_recursion.hpp"

class Subtraction : public MemoizedRecursion<bool, int, int> {
private:
  set<int> ng;

  bool eval(int k, int t) {
    if (t == 0) return true;
    if (k == 100 || ng.count(t)) return false;
    for (int i = 1; i <= 3; ++i) {
      if (t - i >= 0 && solve(k + 1, t - i)) return true;
    }
    return false;
  }

public:
  Subtraction(int ng1, int ng2, int ng3) : ng({ng1, ng2, ng3}) {}
};

int main() {
  int n, ng1, ng2, ng3;
  cin >> n >> ng1 >> ng2 >> ng3;
  Subtraction subtraction(ng1, ng2, ng3);
  cout << (subtraction.solve(0, n) ? "YES" : "NO") << endl;
}