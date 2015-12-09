//
// Created by thisguy on 11/22/15.
//

#include "Airport.h"
#include "Fleet.h"
#include "Passenger.h"
#include <vector>
using namespace std;

namespace Airport {
    Airport::Airport() : fleet(nullptr) {

    }
//    Airport::Airport(vector<Flight*>flightSched, Fleet* fleetList, vector<Passenger*> passList) : flightSchedule(flightSched), fleet(fleetList), passengerList(passList) {
//
//    }
    void Airport::addFlightToSchedule(Flight *newFlight) {
        flightSchedule.push_back(newFlight);
    }
    void Airport::addPassengerToList(Passenger *newPass) {
        passengerList.push_back(newPass);
    }
    void Airport::deleteFlightFromSchedule(Flight *flightDelete) {
        bool found  = false;
        if (!flightSchedule.empty())
        {
            for (int  i=0; i<flightSchedule.size(); i++)
            {
                if (flightSchedule[i] == flightDelete) {
                    found = true;
                    flightSchedule.erase(flightSchedule.begin() + i);
                    break;
                }
            }
        }
        if (!found) {
            cout << "The flight is not in the flight schedule." << endl;
        }

    }
    Flight* Airport::getFlightByIndex(int i) {
        if (0 <= i < flightSchedule.size()) {
            return flightSchedule[i];
        }
        else {
            cout << "The flight you have requested is not in the schedule." << endl;
        }

    }
    int Airport::getSizeOfFlightSchedule() {
        return flightSchedule.size();
    }
    int Airport::getSizeOfPassList() {
        return passengerList.size();
    }
    void Airport::deletePassengerFromList(Passenger *passDelete) {
        bool found  = false;
        if (!passengerList.empty())
        {
            for (int  i=0; i<passengerList.size(); i++)
            {
                if (passengerList[i] == passDelete) {
                    found = true;
                    passengerList.erase(passengerList.begin() + i);
                    break;
                }
            }
        }
        if (!found) {
            cout << "The passenger is not in the passenger list." << endl;
        }
    }
    void Airport::setFleet(Fleet *newFleet) {
        fleet = newFleet;
    }
    Fleet* Airport::getFleet() const {
        return fleet;
    }
    void Airport::printFlights() {
        for (int  i=0; i<flightSchedule.size(); i++)
        {
            cout << i << " ";
            flightSchedule[i]->printFlight();
        }
    }
    void Airport::printPassengers() {
        for (int  i=0; i<passengerList.size(); i++)
        {
            cout << passengerList[i]->getId() << " ";
            passengerList[i]->printPassenger();
        }
    }
    void Airport::printFleet() {
        fleet->showFleet();
    }
    Passenger* Airport::getPassengerById(int i) {
        for (int  i=0; i<passengerList.size(); i++)
        {
            if (passengerList[i]->getId() == i) {
                return passengerList[i];
            }
            cout << "Invalid passenger ID. " << endl;
        }
    }
    Passenger* Airport::getPassengerByIndex(int i) {
        if (0 < i < passengerList.size()) {
            return passengerList[i];
        }
        else cout << "The passenger does not exist at this index." << endl;
    }



}
