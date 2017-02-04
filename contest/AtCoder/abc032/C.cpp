#include "minmax.hpp"
#include "vector.hpp"
#include "dp/double_pointer.hpp"

class Row : public DoublePointer {
private:
  vector<int64_t> s;
  int k;
  int64_t product;
  
  bool valid() {return product <= k;}

  void pop() {product /= s[front];}

  void push() {
    product *= s[back];
    if (product <= k) chmax(res, back - front + 1);
  }

public:
  int res;

  Row(const vector<int64_t>& s, int k) : DoublePointer(s.size()), s(s), k(k), product(1), res(0) {}
};

int main() {
  int n, k;
  cin >> n >> k;
  vector<int64_t> s(n);
  cin >> s;
  if (in(s, int64_t(0))) {
    cout << n << endl;
    return 0;
  }
  Row row(s, k);
  row.solve();
  cout << row.res << endl;
}
