#include "vector.hpp"

int main() {
  vector<int> s(6);
  cin >> s;
  cout << setprecision(2) << (accumulate(s) - max(s) - min(s)) / 4.0 << endl;
}
