//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_AIRPORT_H
#define DATASTRUCTURESFINALPROJECT_AIRPORT_H
#include "Flight.h"
#include "Plane.h"
#include "Passenger.h"
#include "Fleet.h"
#include <vector>
using std::vector;
namespace Airport {
    class Flight;
    class Plane;
    class Passenger;
    class Fleet;
    class Airport {
    public:
        Airport();
        Airport(vector<Flight*> fsched, Fleet* flist, vector<Passenger*> plist);
        void addFlightToSchedule(const Flight* newFlight);
        void addPassengerToList(const Passenger* newPass);
        void deleteFlightFromSchedule(const Flight * flightDelete);
        void deletePassengerFromList(Passenger* passDelete);
        void setFleet(const Fleet* newFleet);
        int getSizeOfPassList();
        Fleet* getFleet() const;
        void printFlights();
        void printPassengers();
        void printFleet();
        Flight* getFlightByIndex(int i);


    private:
        vector<Flight*> flightSchedule;
        Fleet* fleet;
        vector<Passenger*> passengerList;
    };
}
#endif //DATASTRUCTURESFINALPROJECT_AIRPORT_H
