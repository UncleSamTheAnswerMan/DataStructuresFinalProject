//
// Created by thisguy on 11/22/15.
//

#include "Flight.h"
#include <cmath>

namespace Airport {
    Flight::Flight(std::string typeOfPlane) : ID(-1), destination(""), departureTime(0), arrivalTime(0), thePlane(nullptr), planeType(typeOfPlane), basePrice(0) {
        if (planeType != NULL && planeType != "") {
            int numSeats = TypePlane::getNumOfSeats(planeType);
            TypePlane::calcSeats(&numFirstClass, &numEconPlus, &numEcon, numSeats);
            numRows = TypePlane::getNumOfRows(planeType);
            rowsForEcon = numRows/2;
            rowsForFirst = rowsForPlus = rowsForEcon/2;
        }
    }

    Flight::Flight(int newID, Plane *plane, time_t departTime, time_t arriveTime, double price)
            : ID(newID), thePlane(plane), departureTime(departTime), arrivalTime(arriveTime), basePrice(price) {
        planeType = thePlane->getType();
        numFirstClass = thePlane->getFirstClass();
        numEconPlus = thePlane->getEconomyPlus();
        numEcon = thePlane->getEconomy();
        numRows = thePlane->getRows();
        rowsForEcon = numRows/2;
        rowsForFirst = floor((double)rowsForEcon/2);
        rowsForPlus = ceil((double)rowsForEcon/2);

    }

    int Flight::getID() const {
        return ID;
    }

    string Flight::getDestination() const {
        return destination;
    }

    time_t Flight::getDepart() const {
        return departureTime;
    }

    time_t Flight::getArrival() const {
        return arrivalTime;
    }

    Plane* Flight::getPlane() const {
        return thePlane;
    }

    Passenger* Flight::getPassengerForSeat(string seat) {
        Passenger*  thePass;
        Seat* seatPoint = _seatStringConvert(seat);

        return thePass;
    }

    Passenger* Flight::getPassengerForSeat(Seat *seat) {
        Passenger* thePass;

        return thePass;
    }

    Seat* Flight::_seatStringConvert(string seatString) {

    }

    void Flight::_initSeatList() {//TODO in the middle of this function, still have lots of others to do to finish Flight class
        int seatRowFirst = numFirstClass/rowsForFirst;
        int seatRowPlus = numEconPlus/rowsForPlus;
        int seatRowEcon = numEcon/rowsForEcon;
        for (int i = 0; i < rowsForFirst; i++) {

        }
    }
}