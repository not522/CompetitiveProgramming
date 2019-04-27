#include "template.hpp"

int main() {
  int n;
  cin >> n;
  string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
  for (int i = 1; ; i *= 2) {
    for (int j = 0; j < 5; ++j) {
      n -= i;
      if (n <= 0) {
        cout << names[j] << endl;
        return 0;
      }
    }
  }
}
