#include "string/split.hpp"

int main() {
  string d;
  cin >> d;
  auto v = split(d, '/');
  v[1] += v[2];
  sort(v[0].begin(), v[0].end());
  sort(v[1].begin(), v[1].end());
  cout << (v[0] == v[1] ? "yes" : "no") << endl;
}
