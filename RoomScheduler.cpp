//
// Created by karmashka on 4/15/20.
//

#include "RoomScheduler.h"

#include <utility>
std::pair<bool, Reservation>
RoomScheduler::Reserve(size_t room_id, const Interval &i) {
  auto it = rooms_.find(room_id);
  if (it == rooms_.end()) {
    return {false, Reservation()};
  }
  return it->AddReservation(i);
}
std::pair<bool, Reservation> RoomScheduler::Reserve(const Interval &i,
                                                    size_t num_people) {
  auto it = rooms_.lower_bound(num_people);
  if (it->GetNumPeople() < num_people) {
    return {false, Reservation()};
  }
  return it->AddReservation(i);
}
void RoomScheduler::CancelReservation(const Reservation &id) {
  auto it = rooms_.find(id.GetRoomId());
  if (it != rooms_.end()) {
    it->CancelReservation(id.GetIntervalId());
  }
}

bool RoomScheduler::IsOccupied(size_t room_id, const Interval &i) const {
  auto it = rooms_.find(room_id);
}

std::vector<Interval>
RoomScheduler::GetCurrentSchedule(size_t room_id) const {
  auto it = rooms_.find(room_id);
  if (it != rooms_.end()) {
    return it->GetSchedule();
  }
  return {};
}

RoomScheduler::RoomScheduler(): is_initialized_(false) {}

RoomScheduler::RoomScheduler(std::string filename): is_initialized_(true), filename_(std::move(filename)) {
  // TODO
}

void RoomScheduler::LoadFile(const std::string &filename) {
  filename_ = filename;
  is_initialized_ = true;

  // TODO
}
void RoomScheduler::SaveToFile(const std::string &filename) const {
  // TODO
}
void RoomScheduler::SaveToFile() const {
  SaveToFile(filename_);
}

std::vector<Room>
RoomScheduler::GetAvailableRooms(const Interval &i, size_t num_people, size_t rooms_wanted) const {
  auto it = rooms_.lower_bound(num_people);
  if (it == rooms_.end()) {
    return {};
  }
  std::vector<Room> v;
  while (it != rooms_.end() && v.size() < rooms_wanted) {
    v.push_back(*it);
    ++it;
  }
  return std::move(v);
}
