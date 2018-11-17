#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  cin >> s;
  int a = accumulate(s);
  if (a % 10) {
    cout << a << endl;
    return 0;
  }
  sort(s);
  for (int i : s) {
    if ((a - i) % 10) {
      cout << a - i << endl;
      return 0;
    }
  }
  cout << 0 << endl;
}
