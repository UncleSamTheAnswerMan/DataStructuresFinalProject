//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_AIRPORT_H
#define DATASTRUCTURESFINALPROJECT_AIRPORT_H
#include "Flight.h"
#include "Plane.h"
#include "Passenger.h"
#include "Plane.h"
#include <vector>
namespace Airport {
    class Airport {
    private:
        vector<Flight*> flightSchedule;
        Fleet* fleet;
        vector<Passenger*> passengerList;
    };
}
#endif //DATASTRUCTURESFINALPROJECT_AIRPORT_H
