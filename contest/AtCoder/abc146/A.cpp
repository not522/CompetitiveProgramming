#include "string.hpp"

int main() {
  String day[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  String s(in);
  for (int i = 0; i < 7; ++i) {
    if (s == day[i]) {
      cout << 7 - i << endl;
    }
  }
}
