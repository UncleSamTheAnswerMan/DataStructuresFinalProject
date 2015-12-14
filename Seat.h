//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_SEAT_H
#define DATASTRUCTURESFINALPROJECT_SEAT_H
#include "Passenger.h"
#include "Flight.h"
#include <iostream>
#include <ostream>
using namespace std;
namespace Airport {
    class Flight;
    class Passenger;
    class Seat {
    public:
        Seat();
        Seat(const double basePrice);
        Seat(Passenger * const occupant);
        Seat(Flight * const flight);
        Seat(const double basePrice, Flight * const flight);
        Seat(const double basePrice, Passenger * const occupant, Flight* flight);
        Passenger* getOccupant() const;
        double getBasePrice() const;
        Flight* getFlight() const;

        void setOccupant(Passenger* occupant);
        void setBasePrice(const double basePrice);
        void setFlight(Flight* flight);
        void setSeat(const char s);
        void setRow(const int r);
        char getSeat() const;
        int getRow() const;

        virtual void writeToFile(ostream& output);
        virtual void printSeat();
        virtual double calcPrice(double days, double miles) const;

    private:
        Flight* theFlight;
        double thePrice;
        Passenger* theOccupant;
        int row;
        char seat;

    };
}
#endif //DATASTRUCTURESFINALPROJECT_SEAT_H
