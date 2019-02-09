#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  auto c = count_kinds(a);
  for (const auto& i : c) cout << i.first << " " << i.second << endl;
}
