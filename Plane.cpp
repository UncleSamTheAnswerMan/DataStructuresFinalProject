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
    Plane::Plane() : model(nullptr), planeType(nullptr), associatedFleet(nullptr), ID(-1), itinerary(new Itinerary()), noOfSeats(-1), firstClass(-1), economyPlus(-1), economy(-1) {}
    Plane::Plane(string thisModel, TypePlane thisType, Fleet* thisFleet, int thisId, int numbSeats, int fc, int ep, int e) : model(thisModel), planeType(thisType), associatedFleet(thisFleet), ID(thisId), itinerary(new Itinerary()), noOfSeats(numbSeats), firstClass(fc), economyPlus(ep), economy(e) {}

    void Plane::setType(const TypePlane typePlane) {
        planeType = typePlane;
    }
    TypePlane Plane::getType() const {
        return planeType;
    }
    void Plane::setModel(const string newModel) {
        model = newModel;
    }
    string Plane::getModel() const {
        return model;
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

