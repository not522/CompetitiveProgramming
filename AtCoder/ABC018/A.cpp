#include "template.hpp"

int main() {
  array<int, 3> a;
  for (int& i : a) cin >> i;
  for (int i : a) {
    cout << count_if(a.begin(), a.end(), [i](int n){return i <= n;}) << endl;
  }
}
