#include "template.hpp"

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> year(n + 1);
  vector<string> name(n + 1);
  year[0] = 1;
  name[0] = "kogakubu10gokan";
  for (int i = 1; i <= n; ++i) cin >> year[i] >> name[i];
  cout << name[upper_bound(year.begin(), year.end(), q) - year.begin() - 1] << endl;
}
