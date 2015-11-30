//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_SEAT_H
#define DATASTRUCTURESFINALPROJECT_SEAT_H
#include "Passenger.h"
#include "Flight.h"
namespace Airport {
    class Flight;
    class Passenger;
    class Seat {
    public:
        Seat();
        Seat(const double basePrice);
        Seat(const Passenger * const occupant);
        Seat(const Flight * const flight);
        Seat(const double basePrice, const Flight * const flight);
        Seat(const double basePrice, const Passenger * const occupant, const Flight* flight);
        Passenger* getOccupant() const;
        double getBasePrice() const;
        Flight* getFlight() const;

        void setOccupant(const Passenger* occupant);
        void setBasePrice(const double basePrice);
        void setFlight(const Flight* flight);
        void setSeat(const char s);
        void setRow(const int r);
        char getSeat() const;
        int getRow() const;


        double calcPrice(double days, double miles) const;

    private:
        Flight* theFlight;
        double thePrice;
        Passenger* theOccupant;
        int row;
        char seat;

    };
}
#endif //DATASTRUCTURESFINALPROJECT_SEAT_H
