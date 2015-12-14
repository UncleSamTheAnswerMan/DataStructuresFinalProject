//
// Created by thisguy on 11/22/15.
//

#include "EconPlus.h"
#include "Seat.h"
#include "Flight.h"
#include <iostream>

using std::ostream;

namespace Airport {
    EconPlus::EconPlus() : Seat::Seat() {//empty constructor

    }
    EconPlus::EconPlus(double thePrice, Flight* theFlight) : Seat::Seat(thePrice, theFlight) {//full constructor

    }
    double EconPlus::calcPrice(int days) {//calcPrice implemented for EconPlus

        
        if (days >= 30) {
            return (getBasePrice());
        } else if (days >= 8) {
            return ((getBasePrice() * 1.1));
        } else if (days >= 0) {
            return ((getBasePrice() * 1.2));
        } else {
            return -1;
        }
    }

    void EconPlus::writeToFile(ostream &output) {
        if (getOccupant() != nullptr) {
            output << 2 << " " << (getRow()+1) << getSeat() << " " << getOccupant()->getId() << endl;
        }
    }
}