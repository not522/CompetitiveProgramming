#include "vector.hpp"

int main() {
  int n, l;
  cin >> n >> l;
  vector<string> s(n);
  cin >> s;
  sort(s);
  cout << accumulate(s) << endl;
}
