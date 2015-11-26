#include "minmax.hpp"

int main() {
  string n;
  cin >> n;
  string res = n;
  for (size_t i = 0; i < n.size(); ++i) {
    for (size_t j = i + 1; j < n.size(); ++j) {
      string m = n;
      swap(m[i], m[j]);
      chmax(res, m);
    }
  }
  cout << res << endl;
}
