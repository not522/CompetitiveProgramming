#include "template.hpp"

int main() {
  int w, h;
  cin >> w >> h;
  cout << (w * 3 == h * 4 ? "4:3" : "16:9") << endl;
}
