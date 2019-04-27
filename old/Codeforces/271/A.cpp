#include "string/to_string.hpp"

int main() {
  int n;
  cin >> n;
  while (true) {
    ++n;
    string s = to_string(n);
    if (set<char>(s.begin(), s.end()).size() == 4u) {
      cout << n << endl;
      break;
    }
  }
}
