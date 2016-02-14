#include "math/prime.hpp"
#include "dp/double_pointer.hpp"

class UniqueHash : public DoublePointer {
private:
  vector<int> v;
  set<int> s;

  bool valid() {return s.count(v[back]) == 0;}

  void pop() {s.erase(v[front]);}

  void push() {
    s.insert(v[back]);
    if (mx <= s.size()) {
      mx = s.size();
      res = this->front;
    }
  }

public:
  size_t mx = 0, res;

  UniqueHash(const vector<int>& v) : DoublePointer(v.size()), v(v) {}
};

int main() {
  int k, n;
  cin >> k >> n;
  Prime prime(n);
  vector<int> p;
  for (int i = k; i <= n; ++i) if (prime.isPrime(i)) p.emplace_back(i);
  auto v = p;
  for (int& i : v) {
    while (i >= 10) {
      string s = to_string(i);
      i = accumulate(s.begin(), s.end(), 0) - '0' * s.size();
    }
  }
  UniqueHash uh(v);
  uh.solve();
  cout << p[uh.res] << endl;
}
