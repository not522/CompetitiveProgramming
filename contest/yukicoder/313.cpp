#include "string.hpp"

int main() {
  String s(in);
  Vector<int> v(
      {20104, 20063, 19892, 20011, 19874, 20199, 19898, 20163, 19956, 19841});
  for (int i = 0; i < 10; ++i) {
    v[i] -= s.count('0' + i);
  }
  cout << v.find(-1) << " " << v.find(1) << endl;
}
