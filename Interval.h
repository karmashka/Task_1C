//
// Created by karmashka on 4/15/20.
//

#pragma once

#include <chrono>

#include "Id.h"

class Interval: public Id {
  using time_point = std::chrono::time_point<std::chrono::system_clock>;
public:
  Interval() = default;
  Interval(const time_point& p1, const time_point& p2): from(p1), to(p2) {}
  Interval(const Interval& i): Id(i) {}

  bool operator<(const time_point& p) const {
    return from < p;
  }

  bool operator<(const Interval &rhs) const {
    return from < rhs.from && to < rhs.to;
  }
  bool operator>(const Interval &rhs) const { return rhs < *this; }
  bool operator<=(const Interval &rhs) const { return !(rhs < *this); }
  bool operator>=(const Interval &rhs) const { return !(*this < rhs); }

  bool DoInterlap(const Interval& i) const {
    return i.IsTimePointInside(from)
        || i.IsTimePointInside(to)
        || IsTimePointInside(i.from)
        || IsTimePointInside(i.to);
  }

  bool IsTimePointInside(const time_point& p) const {
    return p >= from && p <= to;
  }
private:
  time_point from;
  time_point to;
};
