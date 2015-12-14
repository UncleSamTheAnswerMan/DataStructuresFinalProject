//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_ECONPLUS_H
#define DATASTRUCTURESFINALPROJECT_ECONPLUS_H
#include "Seat.h"
#include "Flight.h"
#include <iostream>

using std::ostream;

namespace Airport {
    class Flight;
    class EconPlus : public Seat {//EconPlusSeat inherits from SeatBaseType
    public:
        double calcPrice(int days);//virtual for subtype poly
        EconPlus();
        EconPlus(double thePrice, Flight* theFlight);
        void writeToFile(ostream& output);
    };
}
#endif //DATASTRUCTURESFINALPROJECT_ECONPLUS_H
