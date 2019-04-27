#include "golden_section_search.hpp"

int main() {
  double p;
  cin >> p;
  auto f = [&](long double x){return x + p / pow(2, x / 1.5);};
  cout << f(goldenSectionSearch(f, 0, p)) << endl;
}
