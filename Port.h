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
    class Port {
    public:
        Port();
        //Airport(vector<Flight*> fsched, Fleet* flist, vector<Passenger*> plist);
        void addFlightToSchedule(Flight* newFlight);
        void addPassengerToList(Passenger* newPass);
        void deleteFlightFromSchedule(Flight * flightDelete);
        void deletePassengerFromList(Passenger* passDelete);
        void setFleet(Fleet* newFleet);
        int getSizeOfPassList();
        int getSizeOfFlightSchedule();
        Fleet* getFleet() const;
        void printFlights();
        void printPassengers();
        void printFleet();
        Flight* getFlightByIndex(int i);
        Passenger* getPassengerById(int i);
        Passenger* getPassengerByIndex(int i);


    private:
        vector<Flight*> flightSchedule;
        Fleet* fleet;
        vector<Passenger*> passengerList;
    };
}
#endif //DATASTRUCTURESFINALPROJECT_AIRPORT_H
