#pragma once
#include "template.hpp"

class String : public std::string {
public:
  String(int n) : std::string(std::to_string(n)) {}

  String(std::istream& cin) {
    cin >> *this;
  }

  void reverse() {
    std::reverse(this->begin(), this->end());
  }
};
