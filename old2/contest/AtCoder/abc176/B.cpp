#include "string.hpp"

int main() {
  String n(in);
  int s = 0;
  for (char c : n) {
    s += c - '0';
  }
  cout << (s % 9 == 0) << endl;
}
