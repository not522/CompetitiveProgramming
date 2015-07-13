#include "template.hpp"

int main() {
  int n;
  cin >> n;
  cout << setw(2) << setfill('0') << n / 3600 << ":";
  cout << setw(2) << setfill('0') << n / 60 % 60 << ":";
  cout << setw(2) << setfill('0') << n % 60 << endl;
}
