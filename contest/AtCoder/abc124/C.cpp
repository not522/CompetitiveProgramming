#include "string.hpp"

int main() {
  String s(in);
  for (int i = 0; i < s.size(); i += 2) {
    s[i] ^= 1;
  }
  cout << min(s.count('0'), s.count('1')) << endl;
}
