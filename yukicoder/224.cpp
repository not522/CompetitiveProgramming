#include "template.hpp"

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  cout << inner_product(s.begin(), s.end(), t.begin(), 0, plus<int>(), not_equal_to<int>()) << endl;
}
