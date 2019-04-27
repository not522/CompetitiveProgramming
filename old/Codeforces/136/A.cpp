#include "string/to_string.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    v[a - 1] = i + 1;
  }
  cout << to_string(v) << endl;
}
