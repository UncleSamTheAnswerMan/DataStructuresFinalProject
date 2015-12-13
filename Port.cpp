//
// Created by thisguy on 11/22/15.
//

#include "Port.h"
#include "Fleet.h"
#include "Passenger.h"
#include <vector>
#include <fstream>

using namespace std;

namespace Airport {
    Port::Port() : fleet(new Fleet(this)) {

    }
//    Port::Port(vector<Flight*>flightSched, Fleet* fleetList, vector<Passenger*> passList) : flightSchedule(flightSched), fleet(fleetList), passengerList(passList) {
//
//    }
    void Port::addFlightToSchedule(Flight *newFlight) {
        flightSchedule.push_back(newFlight);
    }
    void Port::addPassengerToList(Passenger *newPass) {
        passengerList.push_back(newPass);
    }
    void Port::deleteFlightFromSchedule(Flight *flightDelete) {
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
    Flight* Port::getFlightByIndex(int i) {
        if (0 < i < flightSchedule.size()) {
            return flightSchedule[i];
        }
        else {
            cout << "The flight you have requested is not in the schedule." << endl;
        }

    }
    Flight* Port::getFlightById(int id) {
        for (int i = 0; i < getSizeOfFlightSchedule(); i++ ) {
            if (flightSchedule[i]->getID() == id) {
                return flightSchedule[i];
            }
            else {
                cout << "That ID is not in the flight schedule." << endl;
            }
        }

    }
    int Port::getSizeOfFlightSchedule() {
        return flightSchedule.size();
    }
    int Port::getSizeOfPassList() {
        return passengerList.size();
    }
    void Port::deletePassengerFromList(Passenger *passDelete) {
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
    void Port::setFleet(Fleet *newFleet) {
        fleet = newFleet;
    }
    Fleet* Port::getFleet() const {
        return fleet;
    }
    void Port::printFlights() {
        for (int  i=0; i<flightSchedule.size(); i++)
        {
            flightSchedule[i]->printFlight();
        }
    }
    void Port::printPassengers() {
        for (int  i=0; i<passengerList.size(); i++)
        {
            cout << passengerList[i]->getId() << " ";
            passengerList[i]->printPassenger();
        }
    }
    void Port::printFleet() {
        fleet->showFleet();
    }
    Passenger* Port::getPassengerById(int id) {
        for (int  i=0; i<passengerList.size(); i++)
        {
            if (passengerList[i]->getId() == id) {
                return passengerList[i];
            }
        }
        cout << "Invalid passenger ID. " << endl;
    }
    Passenger* Port::getPassengerByIndex(int i) {
        if (0 < i < passengerList.size()) {
            return passengerList[i];
        }
        else cout << "The passenger does not exist at this index." << endl;
    }

    void Port::writeStuffToFile() {
        ofstream flightFile;
        flightFile.open("flightStuff.txt");
        vector<Flight*>::iterator flightIter;
        for (flightIter = flightSchedule.begin(); flightIter != flightSchedule.end(); ++flightIter){
            (*flightIter)->writePlaneFile(flightFile);
        }
        flightFile.close();

        ofstream passFile;
        passFile.open("passengerStuff.txt");
        vector<Passenger*>::iterator passIter;
        for (passIter = passengerList.begin(); passIter != passengerList.end(); ++passIter) {
            (*passIter)->writePassengerFile(passFile);
        }
        passFile.close();

        ofstream planeFile;
        planeFile.open("planeStuff.txt");
        fleet->writePlanes(planeFile);
        planeFile.close();

    }

}
