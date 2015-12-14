//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_FLIGHT_H
#define DATASTRUCTURESFINALPROJECT_FLIGHT_H

#include <time.h>
#include <iostream>
#include <vector>
#include "Passenger.h"
#include "Plane.h"
#include "Seat.h"

using namespace std;
namespace Airport {
    class Plane;
    class Passenger;
    class Seat;
    class Flight {
    public:
        Flight(string typeOfPlane);
        Flight(int newID, Plane* plane, time_t departTime, time_t arriveTime, double price, string end, string start);
        Flight(int newID, string typeOfPlane, time_t departTime, time_t arriveTime, double price, string end, string start);
        int getID() const;
        string getStartingPoint() const;
        string getTypeOfPlane() const;
        string getDestination() const;
        time_t getDepart() const;
        time_t getArrival() const;
        Plane* getPlane() const;
        //Airport* getLayover() const;
        Passenger* getPassengerForSeat(string seat)const;
        Passenger* getPassengerForSeat(Seat* seat)const;
        Seat* getSeatForPassenger(int passID)const;
        int getRowsFirst()const;
        int getRowsPlus()const;
        int getRowsEcon()const;
        int getSeatsRowFirst() const;
        int getSeatsRowPlus() const;
        int getSeatsRowsEcon() const;
        double getPriceOfSeat(string seat);

        void setID(const int newID);
        void setStartingPoint(const string newStart);
        void setDest(const string newDest);
        void setDepart(const time_t depTime);
        void setArrive(const time_t arrTime);
        void setPlane(Plane* plane);
        int bookFlight(Passenger* passenger, string chosenSeat);
        int bookFlight(Passenger* passenger, Seat* chosenSeat);
        void cancelBooking(Passenger* passenger);
        void cancelBooking(const int passID);

        void delayFlight(int timeMinutes);
        void showSeats();
        void showPassengers();

        void _initSeatList();

        void printFlight() const;
        void writePlaneFile(ostream& flightFile, ostream &seatFile);

    private:
        int ID;
        int numFirstClass;
        int numEconPlus;
        int numEcon;
        int numRows;
        int rowsForFirst, rowsForPlus, rowsForEcon;
        int seatRowFirst, seatRowPlus, seatRowEcon;
        int aisleFirst, aislePlus, aisleEcon;
        double basePrice;
        string startingPoint;
        string destination;
        string planeType;
        time_t departureTime;
        time_t arrivalTime;
        Plane* thePlane;

        vector<Passenger*> PassengerList;
        vector<vector<Seat*>> SeatList;
        //Airport* layover;

    };
}
#endif //DATASTRUCTURESFINALPROJECT_FLIGHT_H
