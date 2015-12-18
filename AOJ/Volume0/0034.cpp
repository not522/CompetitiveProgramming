#include "string/split.hpp"

int main() {
  string line;
  while (cin >> line) {
    auto d = split(line, ',');
    vector<int> l(10), v(2), s(10);
    for (int i = 0; i < 10; ++i) l[i] = stoi(d[i]);
    for (int i = 0; i < 2; ++i) v[i] = stoi(d[i + 10]);
    partial_sum(l.begin(), l.end(), s.begin());
    for (int i = 0; i < 10; ++i) {
      if (s[i] * v[1] >= (s.back() - s[i]) * v[0]) {
        cout << i + 1 << endl;
        break;
      }
    }
  }
}
