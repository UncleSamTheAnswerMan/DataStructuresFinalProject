//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_FIRSTCLASS_H
#define DATASTRUCTURESFINALPROJECT_FIRSTCLASS_H
#include "Seat.h"
#include "Flight.h"

namespace Airport {
    class Flight;
    class FirstClass : public Seat{//FirstClassSeat inherits from SeatBaseType
    public:
        virtual double calcPrice(int days, int miles) const;//Virtual for subtype polymorph
        FirstClass();
        FirstClass(double thePrice, Flight* theFlight);
    };
}
#endif //DATASTRUCTURESFINALPROJECT_FIRSTCLASS_H
