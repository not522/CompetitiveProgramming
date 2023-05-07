#include "dp/memoized_recursion.hpp"
#include "vector.hpp"

class Sushi : public MemoizedRecursion<int, int> {
private:
  Vector<int> v;

  int eval(int i) {
    if (i == 0) {
      return v[0];
    }
    if (i == 1) {
      return max(v[0], v[1]);
    }
    return max(solve(i - 1), solve(i - 2) + v[i]);
  }

public:
  Sushi(const Vector<int> &v) : v(v) {}
};

int main() {
  int n(in);
  Vector<int> v(n, in);
  Sushi sushi(v);
  cout << sushi.solve(n - 1) << endl;
}
