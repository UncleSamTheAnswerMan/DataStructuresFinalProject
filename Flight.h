//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_FLIGHT_H
#define DATASTRUCTURESFINALPROJECT_FLIGHT_H

#include <time.h>
#include <vector>
#include "Passenger.h"
#include "Plane.h"

using namespace std;
namespace Airport {
    class Flight {
    public:
        Flight(string typeOfPlane);
        Flight(int newID, Plane* plane, time_t departTime, time_t arriveTime, double price);
        int getID() const;
        string getDestination() const;
        time_t getDepart() const;
        time_t getArrival() const;
        Plane* getPlane() const;
        //Airport* getLayover() const;
        Passenger* getPassengerForSeat(string seat);
        Passenger* getPassengerForSeat(Seat* seat);
        Seat* getSeatForPassenger(int passID);

        void setID(const int newID);
        void setDest(const string newDest);
        void setDepart(const time_t depTime);
        void setArrive(const time_t arrTime);
        void setPlane(const Plane* plane);
        void bookFlight(const Passenger* passenger, const string chosenSeat);
        void bookFlight(const Passenger* passenger, const Seat* chosenSeat);
        void cancelBooking(const Passenger* passenger);
        void cancelBooking(const int passID);

        void delayFlight(int timeMinutes);
        void showSeats();
        void showPassengers();

        void _initSeatList();
        Seat* _seatStringConvert(string seatString);

        void PrintFlight();

    private:
        int ID;
        int numFirstClass;
        int numEconPlus;
        int numEcon;
        int numRows;
        int rowsForFirst, rowsForPlus, rowsForEcon;
        int aisleFirst, aislePlus, aisleEcon;
        double basePrice;
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
