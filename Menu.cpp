//
// Created by thisguy on 11/22/15.
//

#include "Menu.h"
#include <string>
#include "time.h"
#include "TypePlane.h"
#include "Plane.h"
#include <sstream>
using namespace std;
namespace Airport {

    Menu::Menu() : airport(nullptr){

    }
    Menu::Menu(Port* a) : airport(a) {

    }
    string Menu::userSeat(Flight* flight) const {
        //TODO rownumber update
        string chosenSeat;
        int classSeat;
        flight->showSeats();
        stringstream seatStream;
        int rowNumber = -1;
        char seatLetter = ' ';
        string tempString;
        cout << "Select a seat Example: 1A for row 1 and seat A: " << endl;
        cin >> tempString;
        seatStream.str(tempString);
        seatStream >> rowNumber;
        seatStream >> seatLetter;
        seatLetter = toupper(seatLetter);
        int seatNum;
        seatNum = static_cast<int>(seatLetter - 'A');

        if (rowNumber == -1 || seatLetter == ' ') {
            cout << "You did not enter a seat. Please try again." << endl;
            userSeat(flight);
        } else {
            int rowsFirst = flight->getRowsFirst();
            int rowsPlus = flight->getRowsPlus();
            int rowsEcon = flight->getRowsEcon();
            rowNumber--;
            if (rowNumber >= 0 && rowNumber < rowsFirst) {
                if (seatLetter >= 'A' && seatNum < flight->getSeatsRowFirst()) {
                    return seatStream.str();
                } else {
                    cout << "The seat letter you entered is not valid." << endl;
                    userSeat(flight);
                }
            } else if (rowNumber >= rowsFirst && rowNumber < (rowsPlus + rowsFirst)) {
                if (seatLetter >= 'A' && seatNum < flight->getSeatsRowPlus()) {
                    return seatStream.str();
                } else {
                    cout << "The seat letter you entered is not valid." << endl;
                    userSeat(flight);

                }
            } else if (rowNumber >= (rowsPlus+rowsFirst) && rowNumber < (rowsEcon+rowsPlus+rowsFirst)) {
                if (seatLetter >= 'A' && seatNum < flight->getSeatsRowsEcon()) {
                    return seatStream.str();
                } else {
                    cout << "The seat letter you entered is not valid." << endl;
                    userSeat(flight);
                }
            }
        }
    }
    void Menu::cancelPassengerBooking() const {
        Passenger* canceler = userPassenger();
        canceler->cancelFlight();
    }
    string Menu::userTypePlane() const {
        int typeOption;
        string planeType;
        cout << "What kind of plane are you interested in?" << endl;
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

        struct tm timeinfo = {second, minute, hour, day, (month-1), (year-1900)};
//        timeinfo.tm_year = year - 1900;
//        timeinfo.tm_mon = month - 1;
//        timeinfo.tm_mday = day;
//        timeinfo.tm_hour = hour;
//        timeinfo.tm_min = minute;
//        timeinfo.tm_sec = second;

        /* call mktime: timeinfo->tm_wday will be set */
        time_t thetime = mktime ( &timeinfo );

        return thetime;
    }
    Plane* Menu::userPlane() const {
        cout << "Please select a plane by the number next to it: " << endl;
        int choice;
        airport->getFleet()->showFleet();
        cin >> choice;
        cout << "you chose " << choice << endl;
        Plane* planeToChoose = airport->getFleet()->getPlaneById(choice);
        planeToChoose->printPlane();
        cout << "plane printed but not gotten" << endl;
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
       if (airport->getFleet()->getFleetSize() < 1) {
           id = 1;
       }
       else {
           int lastPlaneIndex = airport->getFleet()->getFleetSize();
           Plane *idPlane = airport->getFleet()->getPlaneByIndex(lastPlaneIndex-1);
           id = idPlane->getId() + 1;
       }
       return id;
   }
    int Menu::createFlightId() const {
        int id;
        if (airport->getSizeOfFlightSchedule() < 1) {
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
        cout << "Please select the ID corresponding to the flight: " << endl;
        airport->printFlights();
        cin >> choiceFlight;
        Flight* chosenFlight = airport->getFlightById(choiceFlight);
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
        if (airport->getFleet()->getFleetSize()==0) {
            cout << "There are no planes in the fleet to delete." << endl;
            return;
        } else {
            Plane *planeToChoose = userPlane();
            airport->getFleet()->deletePlane(planeToChoose);
            cout << "You have successfully deleted the plane." << endl;
        }
    }
    void Menu::bookFlightMenu() const {
        if (airport->getSizeOfFlightSchedule() == 0) {
            cout << "There are no flights available at this time." << endl;
            return;
        } else {
            cout << "Please choose a flight to book: " << endl;
            Flight *chosenFlight = userFlight();
            Passenger *chosenPassenger = userPassenger();
            string seat = userSeat(chosenFlight);
            chosenFlight->bookFlight(chosenPassenger, seat);
        }
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
        if (airport->getSizeOfPassList() == 0) {
            cout << "There are no passengers in the passenger list." << endl;
            return;
        } else {
            Passenger *passengerToDelete = userPassenger();
            airport->deletePassengerFromList(passengerToDelete);
            cout << "You have successfully deleted the passenger." << endl;
        }
    }
    void Menu::showPassengerItinerary() const {
        Passenger* showPass = userPassenger();
        showPass->printPassengerFlights();
    }
    void Menu::addFlight() {
        int firstChoice;
        cout << "Select the number corresponding to the option you are interested in : " << endl;
        cout << "1 Select plane by type" << endl;
        cout << "2 Select specific plane by ID" << endl;
        cin >> firstChoice;
        if (firstChoice == 1) {
            string planeType = userTypePlane();
            const int flightId = createFlightId();
            double thePrice = userBasePrice();
            string start = userStartLocation();
            string end = userEndLocation();
            cout << "Please enter a departure time: " << endl;
            time_t depTime = getTime();
            cout << "Please enter an arrival time: " << endl;
            time_t arriveTime = getTime();
            Flight* newFlight = new Flight(flightId,planeType,depTime,arriveTime,thePrice,end,start);
            airport->addFlightToSchedule(newFlight);
        }
        else if (firstChoice == 2) {
            Plane* thePlane = userPlane();
            const int flightId = createFlightId();
            double thePrice = userBasePrice();
            string start = userStartLocation();
            string end = userEndLocation();
            cout << "Please enter a departure time: " << endl;
            time_t depTime = getTime();
            cout << "Please enter an arrival time: " << endl;
            time_t arriveTime = getTime();
            Flight* newFlight = new Flight(flightId,thePlane,depTime,arriveTime,thePrice,end, start);
            airport->addFlightToSchedule(newFlight);
            thePlane->addFlightToItinerary(newFlight);
        }
        else {
            cout << "You did not pick a valid option" << endl;
            addFlight();
        }


    }
    void Menu::deleteFlight() {
        Flight* f = userFlight();
        airport->deleteFlightFromSchedule(f);
    }
    void Menu::showFlights() {
        airport->printFlights();
    }
    void Menu::printPassengersOnAFlight() const {
        cout << "Please choose the flight to view passengers." <<endl;
        Flight* flightToShow = userFlight();
        flightToShow->showPassengers();
    }
    void Menu::changePlaneFlight() {

        if (airport->getSizeOfFlightSchedule() == 0) {
            cout << "There are no flights in the schedule to alter." << endl;
            return;
        } else {
            Flight *flightToChange = userFlight();

            if (flightToChange->getPlane()== nullptr) {
                cout << "The current type of plane is " << flightToChange->getTypeOfPlane();
                cout << "Choose the plane you would like to associate with this flight. Planes must be of the same type." << endl;
                Plane* planeToChoose = userPlane();
                cout << "got plane" << endl;
//                cout << planeToChoose->getType() << endl;
                string whatever = flightToChange->getTypeOfPlane();
                cout << whatever << endl;
                if (!(flightToChange->getTypeOfPlane().compare(planeToChoose->getType()))) {
                    flightToChange->setPlane(planeToChoose);
                    planeToChoose->addFlightToItinerary(flightToChange);
                }
                else {
                    cout << "Those plane types are not compatible." << endl;
                    return;
                }
            } else {
                cout << "Choose the plane you would like to associate with this flight. Planes must be of the same type." << endl;
                Plane* planeToChoose = userPlane();
                string planeType = planeToChoose->getType();
                if (!flightToChange->getPlane()->getType().compare(planeType)) {
                    flightToChange->getPlane()->deleteFlightFromItinerary(flightToChange);
                    flightToChange->setPlane(planeToChoose);
                    planeToChoose->addFlightToItinerary(flightToChange);
                }
                else {
                    cout << "That plane type is not compatible with this flight. Please choose another plane." << endl;
                    return;
                }
            }
        }
    }
    void Menu::outputToFile() {
        airport->writeStuffToFile();
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
        cout << "9 Change a flight's plane" << endl;
        cout << "10 View all passengers on a flight" << endl;
        cout << "11 Cancel a passenger's flight" << endl;
        cout << "12 Show a passenger's itinerary" << endl;
        cout << "13 Save and Quit" << endl;
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
                printPassengersOnAFlight();
            } else if (option==11) {
                cancelPassengerBooking();
            } else if (option==12) {
                showPassengerItinerary();
            } else if (option == 13) {
                outputToFile();
                break;
            } else {
                cout << "You did not pick a valid option." << endl;
                textGUI();
            }
            cout << "Would you like to select another option?" << endl;
            string answer;
            cin >> answer;
            keepGoing = (answer[0] == 'y' || answer[0] == 'Y');
        }
    }
}
