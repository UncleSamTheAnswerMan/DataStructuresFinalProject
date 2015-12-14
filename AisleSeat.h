//
// Created by thisguy on 11/29/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_AISLESEAT_H
#define DATASTRUCTURESFINALPROJECT_AISLESEAT_H

#include "Seat.h"
#include <iostream>

using std::ostream;

namespace Airport {
    class AisleSeat : public Seat {
    public:
        AisleSeat(Flight *f);
        double calcPrice(int days, int miles);
        virtual Passenger* getOccupant() const;
        virtual int getRow() const;
        virtual char getSeat() const;
        void printSeat();
        void writeToFile(ostream& output);

    };
}
#endif
