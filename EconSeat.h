//
// Created by heyi1sam on 10/13/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_FIRSTCLASS_H
#define DATASTRUCTURESFINALPROJECT_FIRSTCLASS_H
#include "Flight.h"
#include "Seat.h"

namespace Airport {

    class EconSeat : public Seat {//EconSeat inherits from SeatBaseType
    public:
        EconSeat();
        EconSeat(double thePrice, Flight* theFlight);
        virtual double calcPrice(int days, int miles) const;//virtual for subtype runtime crap

    };
}
#endif //PROGRAM3_ECONSEAT_H
