#include "string.hpp"

int main() {
  String s(in);
  for (char c : s) {
    cout << char(c ^ 'a' ^ 'A');
  }
  cout << endl;
}
