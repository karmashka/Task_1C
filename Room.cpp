//
// Created by karmashka on 4/15/20.
//

#include "Room.h"
#include "Reservation.h"

bool Room::IsOccupied(const Interval &i) const {
  auto p = reservations_.equal_range(i);
  while (p.first != p.second) {
    if (p.first->DoInterlap(i)) {
      return true;
    }
    ++p.first;
  }
  return false;
}
bool Room::IsOccupied(
    std::chrono::time_point<std::chrono::system_clock> &tp) const {
  for (const auto& p: reservations_) {
    if (p.IsTimePointInside(tp)) {
      return true;
    }
  }
  return false;
}
std::pair<bool, Reservation> Room::AddReservation(const Interval &i) {
  if (IsOccupied(i)) {
    return {false, Reservation()};
  }

}
void Room::CancelReservation(size_t interval_id) const {
  for (auto it = reservations_.begin(); it != reservations_.end(); ++it) {
    if (it->GetId() == interval_id) {
      reservations_.erase(it);
      return;
    }
  }
}
void Room::CancelReservation(const Reservation &r) const {
  CancelReservation(r.GetIntervalId());
}

size_t Room::GetNumPeople() const { return num_people_allowed_; }

std::vector<Interval> Room::GetSchedule() const {
    return std::vector<Interval>(reservations_.begin(), reservations_.end());
}


bool operator==(const Room &r, size_t id) { return r.GetId() == id; }

bool operator<(const Room &r, const size_t num_people) {
  return r.GetNumPeople() < num_people;
}
