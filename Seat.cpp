//
// Created by thisguy on 11/22/15.
//

#include "Seat.h"
#include <iomanip>
#include <iostream>

using std::ostream;

namespace Airport {
    Seat::Seat() : thePrice(0), theFlight(nullptr), theOccupant(nullptr) {

    }

    Seat::Seat(const double basePrice) : thePrice(basePrice), theFlight(nullptr), theOccupant(nullptr) {

    }

    Seat::Seat(Flight* flight) : theFlight(flight), thePrice(0), theOccupant(nullptr) {

    }

    Seat::Seat(Passenger *occupant) : theOccupant(occupant), thePrice(0), theFlight(nullptr) {

    }

    Seat::Seat(const double basePrice, Flight *flight) : thePrice(basePrice), theFlight(flight), theOccupant(nullptr) {

    }

    Seat::Seat(const double basePrice, Passenger* occupant, Flight* flight)
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

    void Seat::setFlight(Flight *flight) {
        theFlight = flight;
    }

    void Seat::setOccupant(Passenger *occupant) {
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

    void Seat::writeToFile(ostream& output) {
        output << 0 << " " << row << seat << " " << theOccupant->getId() << endl;
    }

    double Seat::calcPrice(double days, double miles) const {
        return thePrice;
    }
}