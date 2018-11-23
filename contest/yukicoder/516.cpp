#include "vector.hpp"

int main() {
  vector<string> s(3);
  cin >> s;
  sort(s);
  cout << s[1] << endl;
}
