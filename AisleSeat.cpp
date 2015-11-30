//
// Created by thisguy on 11/29/15.
//
#include "Seat.h"
#include "AisleSeat.h"

namespace Airport {
    AisleSeat::AisleSeat() : Seat::Seat() {double thePrice = 0.0;}
    virtual double AisleSeat::calcPrice(int days, int miles) {
        return 0.0;
    }
    Passenger* AisleSeat::getOccupant() {
        return nullptr;
    }
}