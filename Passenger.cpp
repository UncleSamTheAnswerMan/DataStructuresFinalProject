//
// Created by thisguy on 11/22/15.
//
#include <iostream>
#include "Passenger.h"
#include <ostream>
using namespace std;
namespace Airport {
    Passenger::Passenger() : firstName(""), lastName(""), ID(-1) {}
    Passenger::Passenger(string fName, string lName, int idNo) : firstName(fName), lastName(lName), ID(idNo) {}

    void Passenger::setFirstName(string newfirstName) {
        firstName = newfirstName;
    }
    string Passenger::getFirstName() {
        return firstName;
    }
    void Passenger::setLastName(string newLastName) {
        lastName = newLastName;
    }
    string Passenger::getLastName() {
        return lastName;
    }
    int Passenger::getId(){
        return ID;
    }
    void Passenger::setId(int newId) {
        ID = newId;
    }
    void Passenger::printPassenger() const {
        cout << firstName << " " << lastName << " " << ID << endl;
    }
    void Passenger::updateFlight(Flight* f) {
        bool found  = false;
        if (!Flights.empty())
        {
            for (int  i=0; i<Flights.size(); i++)
            {
                if (Flights[i] == f) {
                    found = true;
                    cout << "That flight is already in your flight list" << endl;
                    break;
                }
            }
        }
        if (!found) {
            Flights.push_back(f);
        }
    }
    void Passenger::cancelFlight() {
        if (Flights.size() < 1) {
            cout << "This passenger doesn't have any flights scheduled." << endl;
        } else {
            int delId;
            cout << "Select the flight you would like to cancel by its ID: " << endl;
            printPassengerFlights();
            cin >> delId;
            for (int i = 0; i < Flights.size(); i++) {
                if (delId == Flights[i]->getID()) {
                    Flights.erase(Flights.begin() + i);
                    cout << "Flight successfully canceled." << endl;
                } else {
                    cout << "That flight ID is not valid." << endl;
                }
            }
        }

    }
    void Passenger::printPassengerFlights() const {
        for (int i=0; i<Flights.size();i++) {
            Flights[i]->printFlight();
        }
    }
    void Passenger::writePassengerFile(ostream &output) {
        output << "passenger\n";
        output << firstName << "\n";
        output << lastName << "\n";
        output << ID << "\n";
        output << "flights\n";
        vector<Flight*>::iterator iter;
        for (iter = Flights.begin(); iter != Flights.end(); iter++) {
            output << (*iter)->getID() << "\n";
        }
        output << "endFlights\n";
        output << "endPassenger\n";
    }

}
