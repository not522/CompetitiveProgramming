#pragma once
#include "template.hpp"

#include <chrono>

struct Timer {
  std::chrono::time_point<std::chrono::system_clock> start;

  Timer() : start(std::chrono::system_clock::now()) {}

  double seconds() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::duration<double>(now - start).count();
  }
};
