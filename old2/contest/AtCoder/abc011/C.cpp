#include "dp/memoized_recursion.hpp"
#include "set.hpp"

class SubtractionDP : public MemoizedRecursion<bool, int, int> {
private:
  Set<int> ng;

  bool eval(int k, int t) {
    if (t == 0) {
      return true;
    }
    if (k == 100 || ng.count(t)) {
      return false;
    }
    for (int i = 1; i <= 3; ++i) {
      if (t - i >= 0 && solve(k + 1, t - i)) {
        return true;
      }
    }
    return false;
  }

public:
  SubtractionDP(int ng1, int ng2, int ng3) : ng({ng1, ng2, ng3}) {}
};

int main() {
  setBoolName("YES", "NO");
  int n(in), ng1(in), ng2(in), ng3(in);
  SubtractionDP subtraction(ng1, ng2, ng3);
  cout << subtraction.solve(0, n) << endl;
}
