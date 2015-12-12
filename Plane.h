//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_PLANE_H
#define DATASTRUCTURESFINALPROJECT_PLANE_H
#include "Fleet.h"
#include "Flight.h"
#include "Seat.h"
#include "TypePlane.h"
#include "Itinerary.h"
#include <iostream>
using std::ostream;

namespace Airport {
    class Fleet;
    class Flight;
    class Seat;
    class TypePlane;
    class Itinerary;
    class Plane {
    private:
        std::string planeType;
        Fleet* associatedFleet;
        int ID;
        Itinerary* itinerary;
        int noOfSeats;
        int firstClass;
        int economyPlus;
        int economy;
        int numOfRows;
    public:
        Plane();
        Plane(std::string theType, Fleet* theFleet, int theId);
        void setType(const std::string planeType);
        std::string getType() const;
        void setFleet(Fleet* newFleet);
        Fleet* getFleet() const;
        void setId(int newId);
        int getId() const;
        void showItinerary()const;
        void showSoonestFlight()const;
        int getTotalNoSeats() const;
        int getFirstClass() const ;
        int getEconomyPlus() const;
        int getEconomy() const;
        int getRows() const;
        void addFlightToItinerary(Flight* flightToAdd);
        void deleteFlightFromItinerary(Flight* flightToDelete);
        void _updateSeatTypes();
        void printPlane();
        void writePlane(ostream& planeFile);


    };
}
#endif //DATASTRUCTURESFINALPROJECT_PLANE_H
