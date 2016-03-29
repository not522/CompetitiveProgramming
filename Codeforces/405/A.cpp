#include "vector.hpp"
#include "string/join.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  sort(a);
  cout << join(a) << endl;
}
