#include "template.hpp"

int main() {
  const string nyanpass = "nyanpass";
  int n;
  cin >> n;
  vector<vector<string>> a(n, vector<string>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[j][i];
      if (a[j][i] == "-") a[j][i] = nyanpass;
    }
  }
  vector<int> res;
  for (int i = 0; i < n; ++i) {
    if (count(a[i].begin(), a[i].end(), nyanpass) == n) res.emplace_back(i);
  }
  cout << (res.size() == 1u ? res[0] + 1 : -1) << endl;
}
