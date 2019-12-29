#include "string.hpp"

int main() {
  String s(in);
  for (int i = 0; i < int(s.size()); i += 2) {
    cout << s[i];
  }
  cout << endl;
}
