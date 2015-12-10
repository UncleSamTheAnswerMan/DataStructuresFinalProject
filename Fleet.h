//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_FLEET_H
#define DATASTRUCTURESFINALPROJECT_FLEET_H
#include <iostream>
#include "Plane.h"
#include "Passenger.h"
#include "Flight.h"
#include "Port.h"
#include <vector>
namespace Airport {
    class Plane;
    class Passenger;
    class Flight;
    class Port;
    class Fleet {
    private:
        vector<Plane*> Planes;
        Port *homePort;
    public:
        Fleet();
        Fleet(Port* a);
        void addPlane(Plane* newPlane);
        void deletePlane(Plane* oldPlane);
        int getFleetSize() const;
        void showFleet();
        Plane* getPlaneByIndex(int i);
        Plane* getPlaneById(int id);
    };


}

#endif //DATASTRUCTURESFINALPROJECT_FLEET_H
