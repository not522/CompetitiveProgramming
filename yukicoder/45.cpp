#include "dp/memoized_recursion.hpp"

class Sushi : public MemoizedRecursion<int> {
private:
  vector<int> v;
  
  int eval(int i) {
    if (i == 0) return v[0];
    if (i == 1) return max(v[0], v[1]);
    return max(solve(i - 1), solve(i - 2) + v[i]);
  }

public:
  Sushi(const vector<int>& v) : v(v) {}
};

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& i : v) cin >> i;
  Sushi sushi(v);
  cout << sushi.solve(n - 1) << endl;
}
