#include "dp/double_pointer.hpp"
#include "math/prime.hpp"
#include "set.hpp"
#include "string.hpp"

class UniqueHash : public DoublePointer {
private:
  Vector<int> v;
  Set<int> s;

  bool valid() { return s.count(v[back]) == 0; }

  void pop() { s.erase(v[front]); }

  void push() { s.insert(v[back]); }

  void result() {
    if (mx <= s.size()) {
      mx = s.size();
      res = this->front;
    }
  }

public:
  int mx = 0, res;

  UniqueHash(const Vector<int> &v) : DoublePointer(v.size()), v(v) {}
};

int main() {
  int k(in), n(in);
  Prime prime(n);
  Vector<int> p;
  for (int i = k; i <= n; ++i) {
    if (prime.isPrime(i)) {
      p.emplace_back(i);
    }
  }
  auto v = p;
  for (int &i : v) {
    while (i >= 10) {
      String s(i);
      i = 0;
      for (char c : s) {
        i += c - '0';
      }
    }
  }
  UniqueHash uh(v);
  uh.solve();
  cout << p[uh.res] << endl;
}
