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
    Plane::Plane() : planeType(NULL), associatedFleet(nullptr), ID(-1), itinerary(), noOfSeats(-1), firstClass(-1), economyPlus(-1), economy(-1) {}
    Plane::Plane(string thisType, Fleet* thisFleet, int thisId) : planeType(thisType), associatedFleet(thisFleet), ID(thisId), itinerary(){
        if (planeType.empty()) {
            noOfSeats = TypePlane::getNumOfSeats(planeType);
            TypePlane::calcSeats(&firstClass, &economyPlus, &economy, noOfSeats);
            numOfRows = TypePlane::getNumOfRows(planeType);
        }
    }

    void Plane::setType(const string typePlane) {
        planeType = typePlane;
        if (planeType.empty()) {
            TypePlane::getNumOfSeats(planeType);
            TypePlane::calcSeats(&firstClass, &economyPlus, &economy, noOfSeats);
        }
    }
    string Plane::getType() const {
        return planeType;
    }
    void Plane::setFleet(Fleet* newFleet) {
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
    void Plane::showItinerary() const{
        itinerary->showAllFlights();
    }
    void Plane::showSoonestFlight() const{
        itinerary->showNextFlight();
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
    int Plane::getRows() const {
        return numOfRows;
    }
    void Plane::printPlane() {
        cout << "ID: " << ID << " Type: " << planeType << endl;
    }
    void Plane::addFlightToItinerary(Flight *flightToAdd) {
        if (itinerary->addFlight(flightToAdd) == 0) {
            cout << "Flight " << flightToAdd->getID() << " successfully added to Plane " << ID << endl;
        }
    }
    void Plane::deleteFlightFromItinerary(Flight *flightToDelete) {
        if (itinerary->deleteFlight(flightToDelete) == 0) {
            cout << "Flight " << flightToDelete->getID() << " successfully removed from Plane " << ID << endl;
        }
    }
    void Plane::_updateSeatTypes() {
        TypePlane::calcSeats(&firstClass, &economyPlus, &economy, noOfSeats);
    }
}

