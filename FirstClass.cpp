//
// Created by thisguy on 11/22/15.
//

#include "FirstClass.h"
#include "Seat.h"
#include "Flight.h"

namespace Airport {
    FirstClass::FirstClass() { }

    FirstClass::FirstClass(double thePrice, Flight *theFlight) : Seat(thePrice, theFlight) {//Full constructor

    }

    double FirstClass::calcPrice(int days, int miles) const {//calcPrice implemented for FirstClass pricing
        if (days >= 30) {
            return (getBasePrice() * 3);
        } else if (days >= 8) {
            return (getBasePrice() * 4);
        } else if (days >= 0) {
            return (getBasePrice() * 5);
        } else {
            return -1;
        }
    }
}