#include "binary_search.hpp"

int main() {
  auto f = [](int m){
    cout << "? " << m << endl;
    int res;
    cin >> res;
    return res;
  };
  cout << "! " << binarySearch(f, 1, 1e9 + 1) << endl;
}
