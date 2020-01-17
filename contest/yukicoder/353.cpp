#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << std::plus<int>()(a, b) << std::endl;
}
