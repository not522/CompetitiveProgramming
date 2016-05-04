#include "template.hpp"

int main() {
  for (int i = 0; i < 1000; ++i) {
    cout << setw(3) << setfill('0') << i << endl;
    string r;
    cin >> r;
  }
}
