//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_SEAT_H
#define DATASTRUCTURESFINALPROJECT_SEAT_H
#include "Passenger.h"
#include "Flight.h"
namespace Airport {
    class Seat {
    public:
        Seat();
        Seat(const double basePrice);
        Seat(const Passenger* occupant);
        Seat(const Flight* flight);
        Seat(const double basePrice, const Flight* flight);
        Seat(const double basePrice, const Passenger* occupant, const Flight* flight);
        Passenger* getOccupant() const;
        double getBasePrice() const;
        Flight* getFlight() const;

        void setOccupant(const Passenger* occupant);
        void setBasePrice(const double basePrice);
        void setFlight(const Flight* flight);

        double calcPrice(double days, double miles);

    private:
        Flight* theFlight;
        double thePrice;
        Passenger* theOccupant;

    };
}
#endif //DATASTRUCTURESFINALPROJECT_SEAT_H
