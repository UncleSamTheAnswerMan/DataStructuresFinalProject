cmake_minimum_required(VERSION 3.3)
project(DataStructuresFinalProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Airport.cpp Airport.h Fleet.cpp Fleet.h Menu.cpp Menu.h Passenger.cpp Passenger.h Seat.cpp Seat.h EconSeat.cpp EconSeat.h EconPlus.cpp EconPlus.h FirstClass.cpp FirstClass.h Plane.cpp Plane.h Flight.cpp Flight.h Itinerary.cpp Itinerary.h)
add_executable(DataStructuresFinalProject ${SOURCE_FILES})