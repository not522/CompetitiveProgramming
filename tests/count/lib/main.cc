#include "count.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  auto c = count(a);
  for (const auto& i : c) cout << i.first << " " << i.second << endl;
}
