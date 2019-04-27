#include "template.hpp"

int main() {
  string s;
  cin >> s;
  cout << count(s.begin(), s.end(), '+') - count(s.begin(), s.end(), '-') << endl;
}
