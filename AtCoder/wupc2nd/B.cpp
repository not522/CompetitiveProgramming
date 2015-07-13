#include "dp/memoized_recursion.hpp"

class Pool : public MemoizedRecursion<int, int> {
private:
  vector<bool> use;
  vector<int> mem;
  string s;

  bool used(int x) {
    return use[x];
  }

  int memo(int x) {
    return mem[x];
  }

  void push(int v, int x) {
    use[x] = true;
    mem[x] = v;
  }

  int eval(int x) {
    if (x <= 3) return s[x] == 'X' ? 1 : 0;
    int res = numeric_limits<int>::max();
    for (int i = 1; i <= 3; ++i) res = min(res, solve(x - i));
    if (s[x] == 'X') ++res;
    return res;
  }

public:
  Pool(const string& s) : use(s.size()), mem(s.size()), s(s) {}
};

int main() {
  int n;
  string s;
  cin >> n >> s;
  Pool pool(s);
  cout << pool.solve(n - 1) << endl;
}
