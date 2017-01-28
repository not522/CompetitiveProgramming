#pragma once
#include "template.hpp"

using namespace std::chrono;

struct Timer {
  time_point<system_clock> start;

  Timer() : start(system_clock::now()) {}

  double seconds() {return duration<double>(system_clock::now() - start).count();}
};
