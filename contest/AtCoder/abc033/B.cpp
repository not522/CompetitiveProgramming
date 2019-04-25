#include "string.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<String> s(n);
  Vector<int> p(n);
  read(s, p);
  int sum = p.accumulate();
  for (int i = 0; i < n; ++i) {
    if (sum < p[i] * 2) {
      cout << s[i] << endl;
      return 0;
    }
  }
  cout << "atcoder" << endl;
}
