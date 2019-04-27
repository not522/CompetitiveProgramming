#include "string.hpp"

int main() {
  String a(in), b(in);
  while (a.size() < b.size()) {
    a = '0' + a;
  }
  while (a.size() > b.size()) {
    b = '0' + b;
  }
  cout << (a > b ? "GREATER" : a < b ? "LESS" : "EQUAL") << endl;
}
