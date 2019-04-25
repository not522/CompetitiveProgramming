#include "string.hpp"

int main() {
  String s(in);
  for (char c = 'A'; c <= 'F'; ++c) {
    cout << s.count(c) << (c != 'F' ? ' ' : '\n');
  }
}
