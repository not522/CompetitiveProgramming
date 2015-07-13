#pragma once
#include "arithmetic.hpp"

struct Time : public arithmetic::Subtraction<Time>{
  int hour, minute, second;

  Time() : hour(0), minute(0), second(0) {}

  Time(int hour, int minute, int second) : hour(hour), minute(minute), second(second) {}

  int toMinutes() const {
    return hour * 60 + minute;
  }

  int toSeconds() {
    return toMinutes() * 60 + second;
  }

  Time operator-=(const Time& time) {
    hour -= time.hour;
    minute -= time.minute;
    second -= time.second;
    if (second < 0) {
      --minute;
      second += 60;
    }
    if (minute < 0) {
      --hour;
      minute += 60;
    }
    return *this;
  }
};
