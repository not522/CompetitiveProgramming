#include "vector.hpp"

int main() {
  Vector<int> h(10, cin);
  h.partial_sort(3, true);
  h.subvector(3).output();
}
