//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_ECONPLUS_H
#define DATASTRUCTURESFINALPROJECT_ECONPLUS_H
#include "Seat.h"
#include "Flight.h"

namespace Airport {

    class EconPlus : public Seat {//EconPlusSeat inherits from SeatBaseType
    public:
        virtual double calcPrice(int days, int miles) const;//virtual for subtype poly
        EconPlus();
        EconPlus(double thePrice, Flight* theFlight);
    };
}
#endif //DATASTRUCTURESFINALPROJECT_ECONPLUS_H
