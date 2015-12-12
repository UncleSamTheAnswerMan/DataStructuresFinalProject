//
// Created by heyi1sam on 10/13/15.
//

#include "EconSeat.h"
#include "Seat.h"
#include "Flight.h"
#include <iostream>

using std::ostream;

namespace Airport {
    EconSeat::EconSeat() {}
    EconSeat::EconSeat(double thePrice, Flight* theFlight) : Seat(thePrice, theFlight) {//full constructor -> also invokes constructor of parent

    }
    double EconSeat::calcPrice(int days, int miles) const{//specific calcPrice for EconSeats
        if (days >= 30) {
            return (getBasePrice());
        } else if (days >= 8) {
            return (getBasePrice() * 1.1);
        } else if (days >= 0) {
            return (getBasePrice() * 1.2);
        } else {
            return -1;
        }
    }

    void EconSeat::writeToFile(ostream &output) {
        output << 3 << " " << getRow() << getSeat() << getOccupant()->getId() << " ";
    }
}