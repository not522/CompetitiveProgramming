#include "binary_search.hpp"

int main() {
  auto f = [](int m) {
    cout << "? " << m << endl;
    return int(in);
  };
  auto res = binarySearch(f, 1, 1e9 + 1);
  cout << "! " << res << endl;
}
