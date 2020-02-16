#include "string.hpp"

int main() {
  String s(in);
  int w(in);
  for (int i = 0; i < s.size(); i += w) {
    cout << s[i];
  }
  cout << endl;
}
