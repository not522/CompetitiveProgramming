#include "dp/memoized_recursion.hpp"
#include "math/mint.hpp"
#include "string.hpp"

class AGC : public MemoizedRecursion<Mint, int, String> {
private:
  Mint eval(int n, String s) {
    if (n == 0) {
      return 1;
    }
    Mint res = 0;
    for (char c : String("ACGT")) {
      auto t = String(c) + s;
      bool ok = !t.contains("AGC");
      for (int i = 0; i < 3; ++i) {
        auto u = t;
        swap(u[i], u[i + 1]);
        if (u.contains("AGC")) {
          ok = false;
        }
      }
      if (ok) {
        res += solve(n - 1, t.substr(0, 3));
      }
    }
    return res;
  }
};

int main() {
  int n(in);
  AGC agc;
  cout << agc.solve(n, "") << endl;
}
