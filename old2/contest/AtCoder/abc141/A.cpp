#include "string.hpp"

int main() {
  String s(in);
  String w[] = {"Sunny", "Cloudy", "Rainy"};
  for (int i = 0; i < 3; ++i) {
    if (s == w[i]) {
      cout << w[(i + 1) % 3] << endl;
    }
  }
}
