//
// Created by thisguy on 11/29/15.
//
#include "Seat.h"
#include "AisleSeat.h"
#include <iostream>

using std::ostream;

namespace Airport {
    AisleSeat::AisleSeat(Flight* f) : Seat::Seat(0,f) {

    }

    double AisleSeat::calcPrice(int days) {
        return 0.0;
    }
    Passenger* AisleSeat::getOccupant() const{
        return nullptr;
    }
    int AisleSeat::getRow() const {
        return -1;
    }
    char AisleSeat::getSeat() const {
        return ' ';
    }
    void AisleSeat::printSeat() {
        cout << "  ";
    }

}