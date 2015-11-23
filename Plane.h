//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_PLANE_H
#define DATASTRUCTURESFINALPROJECT_PLANE_H
#include <iostream>
#include "Fleet.h"
#include "Flight.h"
#include "Seat.h"
#include "TypePlane.h"
#include "Itinerary.h"

namespace Airport {
    class Plane {
    private:
        std::string planeType;
        Fleet* associatedFleet;
        int ID;
        Itinerary itinerary;
        int noOfSeats;
        int firstClass;
        int economyPlus;
        int economy;
    public:
        Plane();
        Plane(std::string theType, Fleet* theFleet, int theId);
        void setType(const std::string planeType);
        std::string getType() const;
        void setFleet(const Fleet* newFleet);
        Fleet* getFleet() const;
        void setId(int newId);
        int getId() const;
        void showItinerary();
        int getTotalNoSeats() const;
        int getFirstClass() const ;
        int getEconomyPlus() const;
        int getEconomy() const;
        void _updateSeatTypes();


    };
}
#endif //DATASTRUCTURESFINALPROJECT_PLANE_H
