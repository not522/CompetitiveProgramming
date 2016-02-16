#include "minmax.hpp"
#include "vector.hpp"
#include "dp/double_pointer.hpp"

class Access : public DoublePointer {
private:
  int k;
  const vector<int> a;

  bool valid() {return a[back] - a[front] <= k;}

  void pop() {}

  void push() {}

  void result() {if (back < n && valid()) chmax(res, back - front + 1);}

public:
  int res;

  Access(const vector<int>& a, int k) : DoublePointer(a.size()), k(k), a(a), res(1) {}
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  cin >> a;
  Access access(a, n);
  access.solve();
  cout << access.res << endl;
}
