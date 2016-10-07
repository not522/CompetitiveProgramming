#include "template.hpp"

int main() {
  int n;
  double va, vb, l;
  cin >> n >> va >> vb >> l;
  cout << l * pow(vb / va, n) << endl;
}
