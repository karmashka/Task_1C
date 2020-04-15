//
// Created by karmashka on 4/15/20.
//

#pragma once

#include <cstdlib>

class Id {
public:
  Id(): id_(++next_id) {}

  Id(const Id & id) = default;
  bool operator==(const size_t id) { return id == id_; }
  bool operator==(const Id &rhs) const { return id_ == rhs.id_; }
  bool operator!=(const Id &rhs) const { return !(rhs == *this); }

  size_t GetId() const {
    return id_;
  }
protected:
  size_t id_;
private:
  static size_t next_id;
};
