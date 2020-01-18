#include "string.hpp"

int main() {
  int n(in);
  String s(in);
  for (char c : s) {
    cout << char((c - 'A' + n) % 26 + 'A');
  }
  cout << endl;
}
