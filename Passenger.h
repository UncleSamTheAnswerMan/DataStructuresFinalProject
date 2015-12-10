//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_PASSENGER_H
#define DATASTRUCTURESFINALPROJECT_PASSENGER_H
#include <iostream>
#include "Flight.h"
#include "Seat.h"
#include <vector>
using std::vector;
namespace Airport {
    class Flight;
    class Seat;
    class Passenger {
    private:
        std::string firstName;
        std::string lastName;
        int ID;
        vector<Flight*> Flights;
    public:
        Passenger();
        Passenger(std::string fName, std::string lName, int ID);
        void updateFlight(Flight* flightToChange);
        std::string getFirstName();
        void setFirstName(std::string newFirstName);
        std::string getLastName();
        void setLastName(std::string newLastName);
        int getId();
        void setId(int newId);
        void printPassenger() const;
        void writePassengerFile(ostream& output);

    };

}
#endif //DATASTRUCTURESFINALPROJECT_PASSENGER_H
