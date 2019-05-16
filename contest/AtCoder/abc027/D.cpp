#include "string.hpp"

int main() {
  String s(in);
  int t = 0;
  Vector<int> v;
  for (char c : s) {
    if (c == '+') {
      ++t;
    }
    if (c == '-') {
      --t;
    }
    if (c == 'M') {
      v.emplace_back(t);
    }
  }
  v.sort();
  for (int i = 0; i < v.size() / 2; ++i) {
    v[i] *= -1;
  }
  cout << v.accumulate() << endl;
}
