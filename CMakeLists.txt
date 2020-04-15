cmake_minimum_required(VERSION 3.15)
project(1CTask)

set(CMAKE_CXX_STANDARD 17)

add_executable(1CTask main.cpp RoomScheduler.cpp RoomScheduler.h Room.cpp Room.h Interval.cpp Interval.h Reservation.cpp Reservation.h Id.cpp Id.h)
