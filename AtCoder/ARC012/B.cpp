#include "template.hpp"

int main() {
  int n;
  double va, vb, l;
  cin >> n >> va >> vb >> l;
  cout << fixed << setprecision(15) << l * pow(vb / va, n) << endl;
}
