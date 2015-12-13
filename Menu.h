//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_MENU_H
#define DATASTRUCTURESFINALPROJECT_MENU_H
#include "Port.h"
#include "Flight.h"
#include "Fleet.h"
#include "Passenger.h"
#include "TypePlane.h"
#include "time.h"

namespace Airport {
    class Menu {
    public:
        Menu();
        Menu(Port * airport);
        time_t getTime();
        string userTypePlane() const;
        Plane* userPlane() const ;
        Passenger* userPassenger() const;
        int createPlaneId() const ;
        int createFlightId() const ;
        int createPassengerId() const;
        double userBasePrice() const ;
        string userStartLocation()const ;
        string userEndLocation()const ;
        Flight* userFlight()const ;
        string userSeat(Flight* f) const;
        void printPassengersOnAFlight() const;
        void cancelPassengerBooking() const;
        void addPlaneMenu() const;
        void deletePlaneMenu() const;
        void bookFlightMenu() const;
        void createPassenger();
        void deletePassenger();
        void addFlight();
        void deleteFlight();
        void showFlights();
        void changePlaneFlight();
        void outputToFile();
        void textGUI();
        int getOption();
    private:
        Port* airport;

    };
}

#endif //DATASTRUCTURESFINALPROJECT_MENU_H
