#include "string.hpp"
#include "vector.hpp"

int main() {
  Vector<String> c(4);
  for (auto &i : c) {
    i = String::getline().reverse();
  }
  c.reverse().output();
}
