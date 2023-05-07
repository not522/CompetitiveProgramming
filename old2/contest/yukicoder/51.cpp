#include "template.hpp"

int main() {
  int w(in), d(in);
  for (; d > 1; --d) {
    w -= w / d / d;
  }
  cout << w << endl;
}
