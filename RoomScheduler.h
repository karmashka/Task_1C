//
// Created by karmashka on 4/15/20.
//

#pragma once

#include <set>
#include <string>
#include <vector>

#include "Interval.h"
#include "Reservation.h"
#include "Room.h"

class RoomScheduler {
public:
  RoomScheduler(const RoomScheduler& r) = delete;
  RoomScheduler& operator=(const RoomScheduler& r) = delete;

  explicit RoomScheduler(std::string  filename);
  RoomScheduler();

  // Throws if error happens.
  void LoadFile(const std::string& filename);
  void SaveToFile(const std::string& filename) const;
  void SaveToFile() const;

  std::pair<bool, Reservation> Reserve(size_t room_id, const Interval& i);
  std::pair<bool, Reservation> Reserve(const Interval& i, size_t num_people = 1);
  void CancelReservation(const Reservation & id);

  bool IsOccupied(size_t room_id, const Interval& i) const;

  std::vector<Room> GetAvailableRooms(const Interval& i, size_t num_people = 1, size_t rooms_wanted = 1) const;
  std::vector<Interval> GetCurrentSchedule(size_t room_id) const;
private:
  std::string filename_;
  bool is_initialized_;
  std::set<Room> rooms_;
};
