#include "vector.hpp"

int get(long long i) {
  cout << setw(10) << setfill('0') << i << endl;
  int x;
  string s;
  cin >> x >> s;
  if (s == "unlocked") exit(0);
  return x;
}

int main() {
  int64_t res = 0;
  string s;
  for (int64_t i = 1e9; i; i /= 10) {
    vector<int> v;
    for (int j = 0; j < 10; ++j) v.emplace_back(get(i * j));
    res = res * 10 + max_element(v);
  }
  get(res);
}
