//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_ITINERARY_H
#define DATASTRUCTURESFINALPROJECT_ITINERARY_H


#include "Flight.h"

namespace Airport {

    class Itinerary {
    public:
        Itinerary();
        int addFlight(const Flight* flightToAdd);
        int deleteFlight(const Flight* flightToDelete);
        Flight* findFlightByTime(const time_t timeToFind);
        Flight* findFlightByID(const int flightID);
        void showAllFlights()const;
        void showNextFlight()const;
        //TODO add sort method
    private:
        vector<Flight*> flightList;
    };
}
#endif //DATASTRUCTURESFINALPROJECT_ITINERARY_H
