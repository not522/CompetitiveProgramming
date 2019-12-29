#pragma once
#include "arithmetic.hpp"

struct Time : public Addition<Time>, public Subtraction<Time> {
  int hour, minute, second;

  Time() : hour(0), minute(0), second(0) {}

  Time(int hour, int minute, int second)
      : hour(hour), minute(minute), second(second) {
    normalize();
  }

  int toMinutes() const { return hour * 60 + minute; }

  int toSeconds() { return toMinutes() * 60 + second; }

  void normalize() {
    while (second < 0) {
      --minute;
      second += 60;
    }
    while (second >= 60) {
      ++minute;
      second -= 60;
    }
    while (minute < 0) {
      --hour;
      minute += 60;
    }
    while (minute >= 60) {
      ++hour;
      minute -= 60;
    }
    while (hour < 0) {
      hour += 24;
    }
    while (hour >= 24) {
      hour -= 24;
    }
  }

  Time &operator+=(const Time &time) {
    hour += time.hour;
    minute += time.minute;
    second += time.second;
    normalize();
    return *this;
  }

  Time &operator-=(const Time &time) {
    hour -= time.hour;
    minute -= time.minute;
    second -= time.second;
    normalize();
    return *this;
  }
};
