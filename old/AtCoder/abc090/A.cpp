#include "vector.hpp"

int main() {
  vector<string> s(3);
  cin >> s;
  for (int i = 0; i < 3; ++i) cout << s[i][i];
  cout << endl;
}
