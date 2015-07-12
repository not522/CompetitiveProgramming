#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  --n;
  cout << s[n / 5] << s[n % 5] << endl;
}
