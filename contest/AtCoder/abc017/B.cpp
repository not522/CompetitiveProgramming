#include "string.hpp"

int main() {
  setBoolName("YES", "NO");
  String x(in);
  while (!x.empty()) {
    if (x.size() >= 2 && x.substr(x.size() - 2) == "ch") {
      x = x.substr(0, x.size() - 2);
    } else if (String("oku").contains(x.back())) {
      x.pop_back();
    } else {
      break;
    }
  }
  cout << x.empty() << endl;
}
