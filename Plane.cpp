//
// Created by thisguy on 11/22/15.
//

#include "Plane.h"
#include <iostream>
#include "Fleet.h"
#include "Flight.h"
#include "Seat.h"
#include "TypePlane.h"
#include "Itinerary.h"
using namespace std;
namespace Airport {
    Plane::Plane() : planeType(NULL), associatedFleet(nullptr), ID(-1), itinerary(new Itinerary()), noOfSeats(-1), firstClass(-1), economyPlus(-1), economy(-1) {}
    Plane::Plane(string thisType, Fleet* thisFleet, int thisId) : planeType(thisType), associatedFleet(thisFleet), ID(thisId), itinerary(new Itinerary()){
        if (planeType != NULL && planeType != "") {
            TypePlane::getNumOfSeats(planeType);
            TypePlane::calcSeats(&firstClass, &economyPlus, &economy, noOfSeats);
        }
    }

    void Plane::setType(const string typePlane) {
        planeType = typePlane;
        if (planeType != NULL && planeType != "") {
            TypePlane::getNumOfSeats(planeType);
            TypePlane::calcSeats(&firstClass, &economyPlus, &economy, noOfSeats);
        }
    }
    string Plane::getType() const {
        return planeType;
    }
    void Plane::setFleet(const Fleet* newFleet) {
        associatedFleet = newFleet;
    }
    Fleet* Plane::getFleet() const {
        return associatedFleet;
    }
    void Plane::setId(const int id) {
        ID = id;
    }
    int Plane::getId() const {
        return ID;
    }
    void Plane::showItinerary() {
        int i = 0;
        for (i = itinerary.getFlightList().begin(); i != itinerary.getFlightList().end; i++) {
            (*i)->printFlight();
        }
    }
    int Plane::getTotalNoSeats() const {
        return noOfSeats;
    }
    int Plane::getFirstClass() const {
        return firstClass;
    }
    int Plane::getEconomyPlus() const {
        return economyPlus;
    }
    int Plane::getEconomy() const {
        return economy;
    }
    void Plane::_updateSeatTypes() {
        planeType.calcSeats(&firstClass, &economyPlus, &economy, noOfSeats);
    }
}

