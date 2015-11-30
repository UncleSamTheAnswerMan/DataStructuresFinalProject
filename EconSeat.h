//
// Created by heyi1sam on 10/13/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_ECONSEAT_H
#define DATASTRUCTURESFINALPROJECT_ECONSEAT_H
#include "Seat.h"
#include "Flight.h"

namespace Airport {
    class Flight;
    class EconSeat : public Seat {//EconSeat inherits from SeatBaseType
    public:
        EconSeat();
        EconSeat(double thePrice, Flight* theFlight);
        virtual double calcPrice(int days, int miles) const;//virtual for subtype runtime crap

    };
}
#endif //PROGRAM3_ECONSEAT_H
