//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_ITINERARY_H
#define DATASTRUCTURESFINALPROJECT_ITINERARY_H


#include "Flight.h"
#include <vector>
using std::vector;
namespace Airport {

    class Itinerary {
    public:
        Itinerary();
        int addFlight(Flight* flightToAdd);
        int deleteFlight(Flight* flightToDelete);
        Flight* findFlightByTime(const time_t timeToFind);
        Flight* findFlightByID(const int flightID);
        void showAllFlights();
        void showNextFlight();
        //TODO add sort method
    private:
        vector<Flight*> flightList;
    };
}
#endif //DATASTRUCTURESFINALPROJECT_ITINERARY_H
