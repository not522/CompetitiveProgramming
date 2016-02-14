#include "math/mint.hpp"
#include "dp/double_pointer.hpp"

class Supplement : public DoublePointer {
private:
  vector<int> f;
  set<int> s;
  Mint c;

  bool valid() {return s.count(f[back]) == 0;}

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
  vector<Mint> dp;

  Supplement(const vector<int> f) : DoublePointer(f.size()), f(f), c(1), dp(f.size() + 1, 1) {}
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> f(n);
  for (int& i : f) cin >> i;
  Supplement supplement(f);
  supplement.solve();
  cout << supplement.dp.back() << endl;
}
