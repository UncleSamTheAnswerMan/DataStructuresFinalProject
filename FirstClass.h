//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_FIRSTCLASS_H
#define DATASTRUCTURESFINALPROJECT_FIRSTCLASS_H
#include "Seat.h"
#include "Flight.h"
#include <iostream>

using std::ostream;

namespace Airport {
    class Flight;
    class FirstClass : public Seat{//FirstClassSeat inherits from SeatBaseType
    public:
        double calcPrice(int days);//Virtual for subtype polymorph
        FirstClass();
        FirstClass(double thePrice, Flight* theFlight);
        void writeToFile(ostream& output);

    };
}
#endif //DATASTRUCTURESFINALPROJECT_FIRSTCLASS_H
