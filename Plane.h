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
        std::string model;
        TypePlane planeType;
        Fleet* associatedFleet;
        int ID;
        Itinerary itinerary;
        int noOfSeats;
        int firstClass;
        int economyPlus;
        int economy;
    public:
        Plane();
        Plane(std::string theModel, TypePlane theType, Fleet* theFleet, int theId, int numSeats, int fc, int ep, int e);
        void setType(const TypePlane planeType);
        TypePlane getType() const;
        void setModel(const std::string newModel);
        std::string getModel() const;
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
