#include "dp/memoized_recursion.hpp"

class Bullion : public MemoizedRecursion<int, int, int, int, int> {
private:
  Vector<Tuple<int, int>> c;

  int eval(int l, int b, int r, int t) {
    int res = 0;
    for (const auto &k : c) {
      if (k.get<0>() < l || r < k.get<0>() || k.get<1>() < b ||
          t < k.get<1>()) {
        continue;
      }
      int a = (r - l) + (t - b) + 1;
      a += solve(l, b, k.get<0>() - 1, k.get<1>() - 1);
      a += solve(k.get<0>() + 1, b, r, k.get<1>() - 1);
      a += solve(l, k.get<1>() + 1, k.get<0>() - 1, t);
      a += solve(k.get<0>() + 1, k.get<1>() + 1, r, t);
      res = max(res, a);
    }
    return res;
  }

public:
  Bullion(const Vector<Tuple<int, int>> &c) : c(c) {}
};

int main() {
  int w(in), h(in), n(in);
  Vector<Tuple<int, int>> c(n, in);
  Bullion bullion(c);
  cout << bullion.solve(1, 1, w, h) << endl;
}
