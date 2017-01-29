#include "vector.hpp"

int main() {
  vector<int> a(3);
  cin >> a;
  sort(a);
  cout << (a == vector<int>({5, 5, 7}) ? "YES" : "NO") << endl;
}
