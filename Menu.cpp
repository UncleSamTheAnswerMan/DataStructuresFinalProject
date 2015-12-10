//
// Created by thisguy on 11/22/15.
//

#include "Menu.h"
#include <string>
#include "time.h"
#include "TypePlane.h"
#include "Plane.h"
using namespace std;
namespace Airport {

    Menu::Menu() : airport(nullptr){

    }
    Menu::Menu(Port* a) : airport(a) {

    }
    string Menu::userTypePlane() const {
        int typeOption;
        string planeType;
        cout << "What kind of plane are you interested in1?" << endl;
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
    time_t Menu::getTime() {
        time_t rawtime;
        struct tm * timeinfo;
        int year, month ,day,hour,minute,second;
        const char * weekday[] = { "Sunday", "Monday",
                                   "Tuesday", "Wednesday",
                                   "Thursday", "Friday", "Saturday"};

        /* prompt user for date */
        printf ("Enter year: "); fflush(stdout); scanf ("%d",&year);
        printf ("Enter month: "); fflush(stdout); scanf ("%d",&month);
        printf ("Enter day: "); fflush(stdout); scanf ("%d",&day);
        printf ("Enter hour: "); fflush(stdout); scanf ("%d",&hour);
        printf ("Enter minute: "); fflush(stdout); scanf ("%d",&minute);
        printf ("Enter second: "); fflush(stdout); scanf ("%d",&second);


        /* get current timeinfo and modify it to the user's choice */

        timeinfo->tm_year = year - 1900;
        timeinfo->tm_mon = month - 1;
        timeinfo->tm_mday = day;
        timeinfo->tm_hour = hour;
        timeinfo->tm_min = minute;
        timeinfo->tm_sec = second;

        /* call mktime: timeinfo->tm_wday will be set */
        time_t thetime = mktime ( timeinfo );

        return thetime;
    }
    Plane* Menu::userPlane() const {
        int choice;
        cout << "Please select a plane by the number next to it: " << endl;
        airport->getFleet()->showFleet();
        cin >> choice;
        Plane* planeToChoose = airport->getFleet()->getPlaneById(choice);
        return planeToChoose;
    }
    Passenger* Menu::userPassenger() const {
        int choicePassenger;
        cout << "Please choose the ID next to the passenger you would like: " << endl;
        airport->printPassengers();
        cin >> choicePassenger;
        Passenger* passenger = airport->getPassengerById(choicePassenger);
        return passenger;
    }
   int Menu::createPlaneId() const {
       int id;
       if (airport->getFleet()->getFleetSize() == 0) {
           id = 1;
       }
       else {
           int lastPlaneIndex = airport->getFleet()->getFleetSize();
           Plane *idPlane = airport->getFleet()->getPlaneByIndex(lastPlaneIndex-1);
           int id = idPlane->getId() + 1;
       }
       return id;
   }
    int Menu::createFlightId() const {
        int id;
        if (airport->getSizeOfFlightSchedule() == 0) {
            id = 1;
        }
        else {
            int lastFlightIndex = airport->getSizeOfFlightSchedule();
            Flight *lastFlight = airport->getFlightByIndex(lastFlightIndex-1);
            id = lastFlight->getID() + 1;
        }
        return id;
    }
    int Menu::createPassengerId() const {
        int id;
        int lastPassIndex = airport->getSizeOfPassList();
        if (lastPassIndex < 1) {
            id = 1;
        }
        else { id=airport->getPassengerByIndex(lastPassIndex-1)->getId()+1; }
        return id;
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
        cout << "You successfully added: " ;
        p->printPlane();
        cout << "to the fleet." << endl;
    }
    void Menu::deletePlaneMenu() const {
        Plane* planeToChoose = userPlane();
        airport->getFleet()->deletePlane(planeToChoose);
        cout << "You have successfully deleted the plane." << endl;
    }
    void Menu::bookFlightMenu() const {

    }
    void Menu::createPassenger() {
        std::string fname;
        std::string lname;
        int id = createPassengerId();
        cout << "Please enter a first name: ";
        cin >> fname;
        cout << "Please enter a last name: ";
        cin >> lname;
        Passenger* passenger = new Passenger(fname, lname, id);
        airport->addPassengerToList(passenger);
    }
    void Menu::deletePassenger() {
        Passenger* passengerToDelete = userPassenger();
        airport->deletePassengerFromList(passengerToDelete);
        cout << "You have successfully deleted the passenger." << endl;
    }
    void Menu::addFlight() {
        string planeType = userTypePlane();
        const int flightId = createFlightId();
        Plane* thePlane = userPlane();
        double thePrice = userBasePrice();
        string start = userStartLocation();
        string end = userEndLocation();
        cout << "Please enter a departure time: " << endl;
        time_t depTime = getTime();
        cout << "Please enter an arrival time: " << endl;
        time_t arriveTime = getTime();
        Flight* newFlight = new Flight(flightId,thePlane,depTime,arriveTime,thePrice,start,end);
        airport->addFlightToSchedule(newFlight);

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
    int Menu::getOption() {
        int chosenOption;
        cout << "Select the number next to the option you are interested in: " << endl;
        cout << "Q Quit" << endl;
        cout << "1 Add a plane to the fleet" << endl;
        cout << "2 Delete a plane from the fleet" << endl;
        cout << "3 Book a flight" << endl;
        cout << "4 Add a new passenger" << endl;
        cout << "5 Delete an existing passenger" << endl;
        cout << "6 Add a flight" << endl;
        cout << "7 Delete a flight" << endl;
        cout << "8 Show flights" << endl;
        cout << "9 Change a plane's flight" << endl;
        cout << "10 Save and Quit" << endl;
        cin >> chosenOption;
        return chosenOption;
    }
    void Menu::textGUI() {
        bool keepGoing = true;
        while (keepGoing) {
            int option = getOption();
            if (static_cast<char>(option) == 'q' || static_cast<char>(option) == 'Q')
            {
                return;
            } else if (option == 1) {
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
                keepGoing = false;
            } else {
                cout << "You did not pick a valid option." << endl;
                textGUI();
            }
            cout << "Would you like to select another option?" << endl;
            string answer;
            cin >> answer;
            keepGoing = (answer[0] == 'y' || answer[0] == 'Y');
        }
        outputToFile();
    }
}
