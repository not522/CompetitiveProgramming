#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int& i : a) cin >> i;
  adjacent_difference(a.begin(), a.end(), b.begin());
  cout << count_if(b.begin(), b.end(), [](int i){return i;}) << endl;
}
