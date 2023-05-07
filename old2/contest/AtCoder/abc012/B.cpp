#include "template.hpp"

int main() {
  int n(in);
  cout << ZeroPadding(2) << n / 3600 << ":";
  cout << ZeroPadding(2) << n / 60 % 60 << ":";
  cout << ZeroPadding(2) << n % 60 << endl;
}
