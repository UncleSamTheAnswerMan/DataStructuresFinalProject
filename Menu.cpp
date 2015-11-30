//
// Created by thisguy on 11/22/15.
//

#include "Menu.h"
using namespace std;
namespace Airport {
    Menu::Menu() : airport(nullptr){

    }
    Menu::Menu(Airport* a) : airport(a) {

    }
    void Menu::addPlane(Plane *p) const {
        airport->getFleet()->addPlane(p);
    }
    void Menu::deletePlane(Plane* p) const {
        airport->getFleet()->deletePlane(p);
    }
    void Menu::bookFlightMenu(Flight* f) const {

    }
    void Menu::createPassenger() {
        std::string fname;
        std::string lname;
        int id = airport->getSizeOfPassList();
        cout << "Please enter a first name: ";
        cin >> fname;
        cout << "Please enter a last name: ";
        cin >> lname;

        Passenger* passenger = new Passenger(fname, lname, id);
        airport->addPassengerToList(passenger);
    }
    void Menu::deletePassenger(Passenger* p) {
        airport->deletePassengerFromList(p);
    }
    void Menu::addFlight(const Flight* f) {
        airport->addFlightToSchedule(f);
    }
    void Menu::deleteFlight(const Flight* f) {
        airport->deleteFlightFromSchedule(f);
    }
    void Menu::showFlights() {
        airport->printFlights();
    }
    void Menu::changePlaneFlight(Flight* f, Plane* p) {
        if (f->getPlane()->getType() == p->getType() ) {
            f->setPlane(p);
        }
        else {
            cout << "That plane type is not compatible with this flight. Please choose another plane." << endl;
        }
    }
    void Menu::outputToFile() {

    }
    void textGUI() {

    }
}
