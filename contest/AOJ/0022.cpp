#include "dp/maximum_subarray.hpp"

int main() {
  for (int n; cin >> n, n != 0;) {
    Vector<int> a(n, cin);
    cout << maximumSubarray(a) << endl;
  }
}
