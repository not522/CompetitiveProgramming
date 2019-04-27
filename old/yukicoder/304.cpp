#include "template.hpp"

int main() {
  string r;
  for (int i = 0; r != "unlocked"; ++i) {
    cout << setw(3) << setfill('0') << i << endl;
    cin >> r;
  }
}
