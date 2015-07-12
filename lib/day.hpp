#pragma once
#include "template.hpp"

inline bool isLeapYear(int year) {
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

inline int getMaxDay(int year, int month) {
  const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2) return isLeapYear(year) ? 29 : 28;
  return days[month];
}

struct Day {
  int year, month, day;

  void next() {
    ++day;
    if (getMaxDay(year, month) < day) {
      ++month;
      day = 1;
      if (month == 13) {
        ++year;
        month = 1;
      }
    }
  }
};
