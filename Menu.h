//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_MENU_H
#define DATASTRUCTURESFINALPROJECT_MENU_H
#include "Airport.h"
#include "Flight.h"
#include "Fleet.h"
#include "Passenger.h"
namespace Airport {
    class Menu {
    public:
        Menu();
        Menu(Airport * airport);
        void addPlane(Plane* p) const;
        void deletePlane(Plane * p) const;
        void bookFlightMenu(Flight* f) const;
        void createPassenger();
        void deletePassenger(Passenger * p);
        void addFlight(const Flight* f);
        void deleteFlight(const Flight* f);
        void showFlights();
        void changePlaneFlight(Flight* f, Plane* p);
        void outputToFile();
        void textGUI();
    private:
        Airport* airport;

    };
}

#endif //DATASTRUCTURESFINALPROJECT_MENU_H
