#include "vector.hpp"

int main() {
  Vector<int> h(10, cin);
  h.partial_sort(3, greater<int>());
  h.subvector(3).output();
}
