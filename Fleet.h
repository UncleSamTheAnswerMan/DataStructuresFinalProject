//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_FLEET_H
#define DATASTRUCTURESFINALPROJECT_FLEET_H
#include <iostream>
#include "Plane.h"
#include "Passenger.h"
#include "Flight.h"
#include "Airport.h"
#include <vector>
namespace Airport {
    class Fleet {
    private:
        vector<Plane*> Planes;
        Airport* homePort;
    public:
        void addPlane(Plane newPlane);
        void deletePlane(Plane oldPlane);
    };


}

#endif //DATASTRUCTURESFINALPROJECT_FLEET_H
