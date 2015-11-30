//
// Created by thisguy on 11/29/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_AISLESEAT_H
#define DATASTRUCTURESFINALPROJECT_AISLESEAT_H

#include "AisleSeat.h"
#include "Seat.h"
namespace Airport {
    class AisleSeat : public Seat {
    public:
        AisleSeat(Flight *f);
        virtual double calcPrice(int days, int miles);
        virtual Passenger* getOccupant() const;
        virtual int getRow() const;
        virtual char getSeat() const;


    };
}
#endif
