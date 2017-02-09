#include "template.hpp"

int main() {
  auto f = [](double n){return floor(n * n / 8 + 0.5);};
  cout << int(f(f(f(20)))) << endl;
}
