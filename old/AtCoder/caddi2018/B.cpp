#include "vector.hpp"

int main() {
  set_bool_name("first", "second");
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  cout << any_of(a, [](int i){return i % 2;}) << endl;
}
