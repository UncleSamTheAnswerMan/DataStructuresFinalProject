//
// Created by thisguy on 11/22/15.
//

#include "Seat.h"

namespace Airport {
    Seat::Seat() : thePrice(0), theFlight(nullptr), theOccupant(nullptr) {

    }

    Seat::Seat(const double basePrice) : thePrice(basePrice), theFlight(nullptr), theOccupant(nullptr) {

    }

    Seat::Seat(const Flight* flight) : theFlight(flight), thePrice(0), theOccupant(nullptr) {

    }

    Seat::Seat(const Passenger *occupant) : theOccupant(occupant), thePrice(0), theFlight(nullptr) {

    }

    Seat::Seat(const double basePrice, const Flight *flight) : thePrice(basePrice), theFlight(flight), theOccupant(nullptr) {

    }

    Seat::Seat(const double basePrice,  const Passenger* occupant, const Flight* flight)
            : thePrice(basePrice), theFlight(flight), theOccupant(occupant) {

    }

    Passenger* Seat::getOccupant() const {
        return theOccupant;
    }

    Flight* Seat::getFlight() const {
        return theFlight;
    }

    double Seat::getBasePrice() const {
        return thePrice;
    }

    void Seat::setBasePrice(const double basePrice) {
        thePrice = basePrice;
    }

    void Seat::setFlight(const Flight *flight) {
        theFlight = flight;
    }

    void Seat::setOccupant(const Passenger *occupant) {
        theOccupant = occupant;
    }

    void Seat::setSeat(const char s) {
        seat = s;
    }

    void Seat::setRow(const int r) {
        row = r;
    }

    char Seat::getSeat() const {
        return seat;
    }

    int Seat::getRow() const {
        return row;
    }


    double Seat::calcPrice(double days, double miles) const {
        return thePrice;
    }
}