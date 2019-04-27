#include "string.hpp"

int main() {
  String o(in), e(in);
  for (int i = 0; i < e.size(); ++i) {
    cout << o[i] << e[i];
  }
  if (o.size() > e.size()) {
    cout << o.back();
  }
  cout << endl;
}
