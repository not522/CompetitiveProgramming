#include "dp/double_pointer.hpp"
#include "math/mint.hpp"
#include "set.hpp"

class Supplement : public DoublePointer {
private:
  Vector<int> f;
  Set<int> s;
  Mint c;

  bool valid() { return s.count(f[back]) == 0; }

  void pop() {
    s.erase(f[front]);
    c -= dp[front];
  }

  void push() {
    dp[back + 1] = c;
    s.insert(f[back]);
    c *= 2;
  }

public:
  Vector<Mint> dp;

  Supplement(const Vector<int> f)
      : DoublePointer(f.size()), f(f), c(1), dp(f.size() + 1, 1) {}
};

int main() {
  int n(in), m(in);
  (void)m;
  Vector<int> f(n, in);
  Supplement supplement(f);
  supplement.solve();
  cout << supplement.dp.back() << endl;
}
