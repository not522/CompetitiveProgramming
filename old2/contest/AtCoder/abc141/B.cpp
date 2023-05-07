#include "string.hpp"

int main() {
  String s(in);
  for (int i = 0; i < s.size(); ++i) {
    if (i % 2 == 0 ? s[i] == 'L' : s[i] == 'R') {
      cout << false << endl;
      return 0;
    }
  }
  cout << true << endl;
}
