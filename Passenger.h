//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_PASSENGER_H
#define DATASTRUCTURESFINALPROJECT_PASSENGER_H
#include <iostream>
#include "Flight.h"
#include "Seat.h"
#include <vector>
#include <ostream>
using std::vector;
using std::ostream;
namespace Airport {
    class Flight;
    class Seat;
    class Passenger {
    private:
        std::string firstName;
        std::string lastName;
        int ID;
        vector<Flight*> Flights;
        vector<Flight*> Cart;
        vector<string> Seats;
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
        void printPassengerFlights() const;
        void cancelFlight();
        void addFlightToCart(Flight* f);
        void showCart() const;
        void deleteFlightFromCart(Flight* f);
        void bookFlightsInCart();
        void addSeatToList(string seat);
        void deleteSeatFromList(string seat);

    };

}
#endif //DATASTRUCTURESFINALPROJECT_PASSENGER_H
