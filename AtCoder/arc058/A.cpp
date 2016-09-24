#include "vector.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<string> d(k);
  cin >> d;
  for (;; ++n) {
    if (find_if(d.begin(), d.end(), [&](string t){return to_string(n).find(t) != string::npos;}) == d.end()) {
      cout << n << endl;
      return 0;
    }
  }
}
