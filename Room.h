//
// Created by karmashka on 4/15/20.
//

#pragma once

#include <chrono>
#include <set>
#include <vector>

#include "Id.h"
#include "Interval.h"

class Reservation;

class Room: public Id {
public:
  explicit Room(size_t num_people = 1): num_people_allowed_(num_people) {}

  size_t GetNumPeople() const;

  bool operator<(size_t num_people) const {
    return num_people_allowed_ < num_people;
  }

  bool operator<(const Room &rhs) const {
    return num_people_allowed_ < rhs.num_people_allowed_;
  }
  bool operator>(const Room &rhs) const { return rhs < *this; }
  bool operator<=(const Room &rhs) const { return !(rhs < *this); }
  bool operator>=(const Room &rhs) const { return !(*this < rhs); }
  std::vector<Interval> GetSchedule() const;

  std::pair<bool, Reservation> AddReservation(const Interval& i);
  void CancelReservation(size_t interval_id) const;
  void CancelReservation(const Reservation& r) const;

  bool IsOccupied(const Interval& i) const;
  bool IsOccupied(std::chrono::time_point<std::chrono::system_clock>& tp) const;
private:
  mutable std::set<Interval> reservations_;
  size_t num_people_allowed_;
};
