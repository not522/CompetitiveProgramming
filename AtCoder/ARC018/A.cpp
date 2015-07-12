#include "template.hpp"

int main() {
  double height, bmi;
  cin >> height >> bmi;
  cout << fixed << setprecision(15) << bmi * height * height / 10000 << endl;
}
