#include "vector.hpp"

int main() {
  Vector<int>(10, in).partial_sort(3, true).subvector(0, 3).output();
}
