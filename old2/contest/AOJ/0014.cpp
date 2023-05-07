#include "template.hpp"

int main() {
  for (int d; d = in, !in.eof;) {
    int area = 0;
    for (int i = 0; i < 600; i += d) {
      area += i * i * d;
    }
    cout << area << endl;
  }
}
