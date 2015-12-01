//
// Created by thisguy on 11/22/15.
//

#include "Menu.h"
#include <string>
#include "TypePlane.h"
using namespace std;
namespace Airport {
    Menu::Menu() : airport(nullptr){

    }
    Menu::Menu(Airport* a) : airport(a) {

    }
    string Menu::userTypePlane() const {
        int typeOption;
        string planeType;
        cout << "What kind of plane would you like to add?" << endl;
        cout << "Select the number next to the model." << endl;
        TypePlane::printTypes();
        cout << "Press 0 to quit." << endl;
        cin >> typeOption;
        if (typeOption == 1) {
            planeType = "A380";
        } else if (typeOption == 2) {
            planeType = "A330";
        } else if (typeOption == 3) {
            planeType = "C130";
        } else if (typeOption == 4) {
            planeType = "Boeing747";
        } else if (typeOption == 5) {
            planeType = "Boeing737";
        } else if (typeOption == 6) {
            planeType = "L1011";
        } else if (typeOption == 0) {
            return NULL;
        } else {
            cout << "That is not a valid plane type." << endl;
            userTypePlane();
        }
        return planeType;
    }
    Plane* Menu::userPlane() const {
        int choice;
        cout << "Please select a plane by the number next to it: " << endl;
        airport->getFleet()->showFleet();
        cin >> choice;
        Plane* planeToChoose = airport->getFleet()->getPlaneByIndex(choice);
        return planeToChoose;
    }
    Passenger* Menu::userPassenger() const {

    }
    int Menu::createPlaneId() const {
        return airport->getFleet()->getFleetSize();
    }
    double Menu::userBasePrice()const {
        double thePrice;
        cout << "Please enter a base price: " << endl;
        cin >> thePrice;
        return thePrice;
    }
    string Menu::userStartLocation() const {
        string startLocation;
        cout << "Please enter a starting location: " << endl;
        cin >> startLocation;
        return startLocation;
    }
    string Menu::userEndLocation() const {
        string endLocation;
        cout << "Please enter an ending location: " << endl;
        cin >> endLocation;
        return endLocation;

    }
    Flight* Menu::userFlight() const {
        int choiceFlight;
        cout << "Please select the number corresponding to the flight: " << endl;
        airport->printFlights();
        cin >> choiceFlight;
        Flight* chosenFlight = airport->getFlightByIndex(choiceFlight);
        return chosenFlight;
    }

    void Menu::addPlaneMenu() const {
        string planeType = userTypePlane();
        Fleet* ourFleet = airport->getFleet();
        int planeId = createPlaneId();
        Plane* p = new Plane(planeType, ourFleet, planeId);
        airport->getFleet()->addPlane(p);
    }
    void Menu::deletePlaneMenu() const {
        Plane* planeToChoose = userPlane();
        airport->getFleet()->deletePlane(planeToChoose);
    }
    void Menu::bookFlightMenu() const {

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
    void Menu::deletePassenger() {
        //airport->deletePassengerFromList(p);
        cout << "TODO" << endl;
    }
    void Menu::addFlight() {
        string planeType = userTypePlane();
        const int flightId = createPlaneId();
        Plane* thePlane = userPlane();
        double thePrice = userBasePrice();
        string start = userStartLocation();
        string end = userEndLocation();

    }
    void Menu::deleteFlight() {
        Flight* f = userFlight();
        airport->deleteFlightFromSchedule(f);
    }
    void Menu::showFlights() {
        airport->printFlights();
    }
    void Menu::changePlaneFlight() {
        Flight* flightToChange = userFlight();
        string planeType = userTypePlane();
        if (flightToChange->getPlane()->getType().compare(planeType)) {
            flightToChange->getPlane()->setType(planeType);
        }
        else {
            cout << "That plane type is not compatible with this flight. Please choose another plane." << endl;
        }
    }
    void Menu::outputToFile() {

    }
    int getOption() {
        int chosenOption;
        cout << "Select the number next to the option you are interested in: " << endl;
        cout << "1 Add a plane to the fleet" << endl;
        cout << "2 Delete a plane from the fleet" << endl;
        cout << "3 Book a flight" << endl;
        cout << "4 Add a new passenger" << endl;
        cout << "5 Delete an existing passenger" << endl;
        cout << "6 Add a flight" << endl;
        cout << "7 Delete a flight" << endl;
        cout << "8 Show flights" << endl;
        cout << "9 Change a plane's flight" << endl;
        cout << "10 Close and output data to file" << endl;
        cin >> chosenOption;
        return chosenOption;
    }
    void Menu::textGUI() {
        bool keepGoing = true;
        while (keepGoing) {
            int option = getOption();
            if (option == 1) {
                addPlaneMenu();
            } else if (option == 2) {
                deletePlaneMenu();
            } else if (option == 3) {
                bookFlightMenu();
            } else if (option == 4) {
                createPassenger();
            } else if (option == 5) {
                deletePassenger();
            } else if (option == 6) {
                addFlight();
            } else if (option == 7) {
                deleteFlight();
            } else if (option == 8) {
                showFlights();
            } else if (option == 9) {
                changePlaneFlight();
            } else if (option == 10) {
                outputToFile();
            } else {
                cout << "You did not pick a valid option." << endl;
                textGUI();
            }
            cout << "Would you like to select another option?" << endl;
            string answer;
            cin >> answer;
            if (answer[0] == 'y') {
                keepGoing = true;
            }
            else if (answer[0] == 'Y') {
                keepGoing = true;
            } else {
                keepGoing = false;
            }
        }
    }
}
