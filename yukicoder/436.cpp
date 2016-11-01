#include "template.hpp"

int main() {
  string s;
  cin >> s;
  cout << min(count(s.begin(), s.end(), 'c') - 1, count(s.begin(), s.end(), 'w')) << endl;
}
