#include "dp/maximum_subarray.hpp"

int main() {
  for (int n; n = in, n != 0;) {
    Vector<int> a(n, in);
    cout << maximumSubarray(a) << endl;
  }
}
