#include "vector.hpp"

int main() {
  int n, a = 0, b = 0;
  string s;
  cin >> n >> s;
  for (char c : s) {
    if (c == '(') {
      ++a;
    } else {
      --a;
      chmin(b, a);
    }
  }
  cout << string(-b, '(') << s << string(-b + count(s, '(') - count(s, ')'), ')') << endl;
}
