#include "minmax.hpp"
#include "vector.hpp"
#include "dp/double_pointer.hpp"

class Row : public DoublePointer {
private:
  vector<long long> s;
  int k;
  long long product;
  
  bool valid() {return product <= k;}

  void pop() {product /= s[front];}

  void push() {
    product *= s[back];
    if (product <= k) chmax(res, back - front + 1);
  }

public:
  int res;

  Row(const vector<long long>& s, int k) : DoublePointer(s.size()), s(s), k(k), product(1), res(0) {}
};

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> s(n);
  cin >> s;
  if (in(s, 0ll)) {
    cout << n << endl;
    return 0;
  }
  Row row(s, k);
  row.solve();
  cout << row.res << endl;
}
