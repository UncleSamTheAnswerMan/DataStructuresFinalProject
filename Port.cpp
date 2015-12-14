//
// Created by thisguy on 11/22/15.
//

#include "Port.h"
#include "Fleet.h"
#include "Passenger.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

namespace Airport {
    Port::Port() : fleet(new Fleet(this)) {
        readFromFile();
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
        }
        cout << "That ID is not in the flight schedule." << endl;

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

    Plane* Port::getPlaneByID(int ID) {
        return fleet->getPlaneById(ID);
    }

    void Port::writeStuffToFile() {
        ofstream flightFile;
        ofstream seatFile;
        flightFile.open("flightStuff.txt");
        seatFile.open("seatStuff.txt");
        vector<Flight*>::iterator flightIter;
        for (flightIter = flightSchedule.begin(); flightIter != flightSchedule.end(); ++flightIter){
            (*flightIter)->writePlaneFile(flightFile, seatFile);
        }
        seatFile.close();
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

    void Port::readFromFile() {
        cout << "readFromFile start" << endl;
        ifstream flightFile;
        flightFile.open("flightStuff.txt");
        vector<int> planeIDList;
        vector<int>flightIDList;
        string flightString;
        cout <<"flight while" << endl;
        while (flightFile >> flightString) {
            if (!flightString.compare("flight")) {
                double price;
                string start;
                string end;
                string type;
                time_t depTime;
                time_t arrTime;
                int thisID;
                flightFile>>thisID;
                flightFile>>price;
                flightFile>>start;
                flightFile>>end;
                flightFile>>type;
                flightFile>>depTime;
                flightFile>>arrTime;
                string temp;
                flightFile>>temp;
                if (temp.compare("endFlight")){
                    int planeID = atoi(temp.c_str());
                    planeIDList.push_back(planeID);
                    flightIDList.push_back(thisID);

                }
                Flight* tempFlight = new Flight(thisID, type, depTime, arrTime, price, end, start);
                flightSchedule.push_back(tempFlight);

            } else if (!flightString.compare("endFlight")) {
                continue;
            }
        }
        flightFile.close();
        cout << "flight closed" << endl;

        ifstream planeFile;
        planeFile.open("planeStuff.txt");
        string planeString;
        cout << "plane file" << endl;
        while(planeFile>>planeString) {
            if (!planeString.compare("plane")) {
                int planeID;
                string type;
                planeFile >> planeID;
                planeFile>> type;
                Plane* tempPlane = new Plane(type, fleet, planeID);
                fleet->addPlane(tempPlane);

            } else if (!flightString.compare("endFlight")) {
                continue;
            }
        }
        planeFile.close();
        cout << "plane closed" << endl;


        for (int i = 0; i < flightIDList.size(); i++) {
            Flight* tempFlight = getFlightById(flightIDList[i]);
            Plane* tempPlane = getPlaneByID(planeIDList[i]);
            if (tempFlight != nullptr && tempPlane != nullptr) {
                tempFlight->setPlane(tempPlane);
                tempPlane->addFlightToItinerary(tempFlight);
            }
        }

        ifstream passFile;
        passFile.open("passengerStuff.txt");
        string passString;
        cout << "passFile" << endl;
        while(passFile>>passString){
            if (!passString.compare("passenger")){
                string first;
                string last;
                int passID;
                passFile>>first;
                passFile>>last;
                passFile>>passID;
                Passenger* tempPass = new Passenger(first, last, passID);
                passengerList.push_back(tempPass);
            } else if (!passString.compare("endPassenger")) {
                continue;
            }
        }
        passFile.close();
        cout << "pass file closed" << endl;

        ifstream seatFile;
        seatFile.open("seatStuff.txt");
        string seatString;
        cout<<"seatFile"<<endl;
        int flightID = 0;
        while (getline(seatFile,seatString)) {
            if (!seatString.substr(0,6).compare("flight")) {
                stringstream streaming;
                streaming.str(seatString);
                string useless;
                streaming >> useless;
                streaming >> flightID;
            } else if (!seatString.compare("endFlight")){
                continue;
            } else {
                stringstream streamTastic;
                streamTastic.str(seatString);
                int type;
                string seatChoice;
                int occID;
                streamTastic >> type;
                streamTastic>>seatChoice;
                streamTastic>> occID;

                Passenger* tempPass = getPassengerById(occID);
                Flight* tempFlight = getFlightById(flightID);
                tempFlight->bookFlight(tempPass, seatChoice);
            }
        }
        seatFile.close();
        cout << "seatFile Closed" << endl;

    }

}
