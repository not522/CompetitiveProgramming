#include "vector.hpp"

int main() {
  Vector<int> s(6, in);
  cout << std::setprecision(2) << (s.accumulate() - s.max() - s.min()) / 4.0
       << endl;
}
