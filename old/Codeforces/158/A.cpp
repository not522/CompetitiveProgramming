#include "template.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int& i : v) cin >> i;
  sort(v.begin(), v.end(), greater<int>());
  int t = v[k - 1];
  if (t == 0) t = 1;
  cout << count_if(v.begin(), v.end(), [&](int i){return i >= t;}) << endl;
}
