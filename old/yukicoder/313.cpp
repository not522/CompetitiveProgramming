#include "vector.hpp"

int main() {
  string s;
  cin >> s;
  vector<int> v({20104, 20063, 19892, 20011, 19874, 20199, 19898, 20163, 19956, 19841});
  for (int i = 0; i < 10; ++i) v[i] -= count(s.begin(),  s.end(), char('0' + i));
  cout << find(v, -1) << " " << find(v, 1) << endl;
}
