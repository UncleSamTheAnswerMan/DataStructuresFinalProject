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
    double EconPlus::calcPrice(int days, int miles) const{//calcPrice implemented for EconPlus

        int distPrice = 0;
        if (miles < 800) {
            distPrice = 75;
        } else {
            distPrice = 125;
        }
        if (days < 30) {
            distPrice += 10;
        }
        if (days >= 30) {
            return (getBasePrice() + distPrice);
        } else if (days >= 8) {
            return ((getBasePrice() * 1.1) + distPrice);
        } else if (days >= 0) {
            return ((getBasePrice() * 1.2) + distPrice);
        } else {
            return -1;
        }
    }

    void EconPlus::writeToFile(ostream &output) {
        if (getOccupant() != nullptr) {
            output << 2 << " " << getRow() << getSeat() << " " << getOccupant()->getId() << endl;
        }
    }
}