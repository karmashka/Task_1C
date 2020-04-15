//
// Created by karmashka on 4/15/20.
//

#pragma once

#include <utility>

#include "Room.h"

class Reservation {
public:
  Reservation() = default;
  Reservation(Room  r, const Interval& i): room_(std::move(r)), interval_(i) {
  }

  bool operator==(const Reservation & r) const{
    return room_ == r.room_ && interval_ == r.interval_;
  }

  size_t GetRoomId() const {
    return room_.GetId();
  }

  size_t GetIntervalId() const {
    return interval_.GetId();
  }

  std::pair<size_t, size_t> GetId() const {
    return {GetRoomId(), GetIntervalId()};
  }

  const std::string &GetName() const { return name_; }

  void SetName(const std::string &name) { name_ = name; }

  const std::string &GetDescription() const { return description_; }

  void SetDescription(const std::string &description) {
    description_ = description;
  }
private:
  Room room_;
  Interval interval_;

  std::string name_;
  std::string description_;
};
