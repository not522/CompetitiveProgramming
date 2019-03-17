#include "vector.hpp"

int main() {
  Vector<int> a(5, cin);
  a.rsort();
  a.output(' ');
}
