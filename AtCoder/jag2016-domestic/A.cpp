#include "vector.hpp"

int main() {
  int n, cnt = 0;
  cin >> n;
  vector<string> s(n);
  cin >> s;
  for (auto i : s) {
    if (i == "A") {
      ++cnt;
    } else {
      --cnt;
      if (cnt < 0) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << (cnt == 0 ? "YES" : "NO") << endl;
}
