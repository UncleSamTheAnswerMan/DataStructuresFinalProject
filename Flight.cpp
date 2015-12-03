//
// Created by thisguy on 11/22/15.
//

#include "Flight.h"
#include "Seat.h"
#include "FirstClass.h"
#include "EconSeat.h"
#include "EconPlus.h"
#include "AisleSeat.h"
#include "Fleet.h"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>

namespace Airport {
    Flight::Flight(std::string typeOfPlane) : ID(-1), destination(""), departureTime(0), arrivalTime(0), thePlane(nullptr), planeType(typeOfPlane), basePrice(0) {
        if (planeType.empty()) {
            int numSeats = TypePlane::getNumOfSeats(planeType);
            TypePlane::calcSeats(&numFirstClass, &numEconPlus, &numEcon, numSeats);
            numRows = TypePlane::getNumOfRows(planeType);
            _initSeatList();

        }
    }

    Flight::Flight(int newID, Plane *plane, time_t departTime, time_t arriveTime, double price, string end, string start)
            : ID(newID), thePlane(plane), departureTime(departTime), arrivalTime(arriveTime), basePrice(price),
                destination(end), startingPoint(start) {
        planeType = thePlane->getType();
        numFirstClass = thePlane->getFirstClass();
        numEconPlus = thePlane->getEconomyPlus();
        numEcon = thePlane->getEconomy();
        numRows = thePlane->getRows();
        _initSeatList();

    }

    int Flight::getID() const {
        return ID;
    }

    string Flight::getStartingPoint() const {
        return startingPoint;
    }

    string Flight::getDestination() const {
        return destination;
    }

    time_t Flight::getDepart() const {
        return departureTime;
    }

    time_t Flight::getArrival() const {
        return arrivalTime;
    }

    Plane* Flight::getPlane() const {
        return thePlane;
    }

    Passenger* Flight::getPassengerForSeat(string seat) const{
        Passenger*  thePass;
        stringstream seatStream;
        seatStream.str(seat);
        int rowNum, seatNum;
        char seatChar;
        seatStream >> rowNum;
        seatStream >> seatChar;
        seatChar = toupper(seatChar);
        seatNum = static_cast<int>(seatChar - 'A');
        if (seatNum < SeatList[rowNum].size() && rowNum < numRows) {
            thePass = SeatList[rowNum][seatNum]->getOccupant();
        }

        return thePass;
    }

    Passenger* Flight::getPassengerForSeat(Seat *seat) const{
        return seat->getOccupant();
    }

    Seat* Flight::getSeatForPassenger(int passID) const {
        for (int i = 0; i < SeatList.size(); i++) {
            for (int j = 0; j < SeatList[i].size(); j++) {
                if (SeatList[i][j]->getOccupant()->getId()== passID) {
                    return SeatList[i][j];
                }
            }
        }
        return nullptr;
    }

    void Flight::setID(const int newID) {
        ID = newID;
    }

    void Flight::setStartingPoint(const string newStart) {
        startingPoint = newStart;
    }

    void Flight::setDest(const string newDest) {
        destination = newDest;
    }

    void Flight::setDepart(const time_t depTime) {
        departureTime = depTime;
    }

    void Flight::setArrive(const time_t arrTime) {
        arrivalTime = arrTime;
    }

    void Flight::setPlane(Plane *plane) {
        thePlane = plane;
    }

    int Flight::bookFlight(Passenger *passenger, string chosenSeat) {
        stringstream seatStream;
        seatStream.str(chosenSeat);
        int rowNum, seatNum;
        char seatChar;
        seatStream >> rowNum;
        seatStream >> seatChar;
        seatChar = toupper(seatChar);
        seatNum = static_cast<int>(seatChar - 'A');
        Seat *theSeat;
        if (rowNum < numRows && seatNum < SeatList[rowNum].size()) {
            theSeat = SeatList[rowNum][seatNum];
        }

        return bookFlight(passenger, theSeat);
    }

    int Flight::bookFlight(Passenger *passenger, Seat *chosenSeat) {
        bool foundPass = false;
        for (int i = 0; i < PassengerList.size(); i++) {
            if (PassengerList[i]->getId() == passenger->getId()) {
                foundPass = true;
            }
        }
        if (!foundPass) {
            PassengerList.push_back(passenger);
            passenger->updateFlight(this);
        }
        if (chosenSeat != nullptr && chosenSeat->getOccupant() == nullptr && (chosenSeat->getRow() != -1)) {
            chosenSeat->setOccupant(passenger);
        } else if (chosenSeat == nullptr){
            cout<<"Improper seat chosen"<<endl;
            return -1;
        } else if (chosenSeat->getRow() == -1) {
            cout << "You can't sit in the aisle, silly. How would anybody get around on the plane?"<<endl;
        }else {
            cout<<"Seat already taken" <<endl;
            return -1;
        }
        return 0;

    }

    void Flight::cancelBooking(const int passID) {

    }//TODO extension to add later

    void Flight::cancelBooking(Passenger *passenger) {

    }//TODO extension to add later

    void Flight::delayFlight(int timeMinutes) {
        departureTime += (timeMinutes * 60);
    }

    void Flight::showSeats() {
        for (int i = 0; i < SeatList.size(); i++) {
            cout <<setw(11) << left << "Row " << (i+1) << ": ";
            cout << setw(seatRowEcon * 3 + 2) << left;
            for (int j = 0; j < SeatList[i].size(); j++) {
                if (SeatList[i][j]->getOccupant() == nullptr) {
                    int row = SeatList[i][j]->getRow();
                    char seat = SeatList[i][j]->getSeat();
                    if (row >= 0) {
                        cout << seat << " ";
                    } else {
                        cout << "  ";
                    }
                } else {
                    cout << "X";
                }
            }
            cout << endl;
        }
    }

    void Flight::showPassengers() {
        vector<Passenger*>::iterator iter;
        for (iter = PassengerList.begin(); iter != PassengerList.end(); iter++) {
            cout << (*iter)->getLastName() << ", " << (*iter)->getFirstName() << ": " << (*iter)->getId() << endl;
        }
    }

    void Flight::printFlight() const {
        cout << setw(40) << left << "Flight ID: " << right << ID << endl;
        cout << setw(40) << left << "Plane Type: " << right << planeType << endl;
        cout << setw(40) << left << "Plane ID: " << right << thePlane->getId() << endl;
        cout << setw(40) << left << "Starting Seat Price: " << right << basePrice << endl;
        cout << setw(40) << left << "Total Number of Seats: " << right << (numFirstClass + numEcon + numEconPlus) << endl;
        cout << setw(40) << left << "->First Class Seats: " << right << numFirstClass-1 << endl;
        cout << setw(40) << left << "->Economy Plus Seats: " << right << numEconPlus-1 << endl;
        cout << setw(40) << left << "->Economy Seats: " << right << numEcon-1 << endl;

        cout << setw(40) << left << "Flight Starting Location: " << right << startingPoint << endl;
        cout << setw(40) << left << "Flight Destination: " << right << destination << endl;
        cout << setw(40) << left << "Departure Time: " << right << ctime(&departureTime) << endl;
        cout << setw(40) << left << "Arrival Time: " << right << ctime(&arrivalTime) << endl;


    }

    void Flight::_initSeatList() {

        rowsForEcon = numRows/2;
        rowsForFirst = floor((double)rowsForEcon/2);
        rowsForPlus = ceil((double)rowsForEcon/2);

        seatRowFirst = numFirstClass/rowsForFirst;
        seatRowPlus = numEconPlus/rowsForPlus;
        seatRowEcon = numEcon/rowsForEcon;

        aisleFirst = floor((double)seatRowFirst/2);
        aislePlus = floor((double)seatRowPlus/2);
        aisleEcon = floor((double)seatRowEcon/2);

        //need to increment numSeats to add in aisle
        numFirstClass++;
        numEconPlus++;
        numEcon++;

        for (int i = 0; i < rowsForFirst; i++) {
            vector<Seat*> tempList;
            for (int j = 0; j < seatRowFirst; j++) {
                Seat *temp;
                if (j == aisleFirst) {
                    temp = new AisleSeat(this);
                } else {
                    temp = new FirstClass(basePrice, this);
                }
                tempList.push_back(temp);
            }
            SeatList.push_back(tempList);
        }

        for (int i = 0; i < rowsForPlus; i++) {
            vector<Seat*> tempList;
            for (int j = 0; j < seatRowPlus; j++) {
                Seat *temp;
                if (j == aislePlus) {
                    temp = new AisleSeat(this);
                } else {
                    temp = new EconPlus(basePrice, this);
                }
                tempList.push_back(temp);
            }
            SeatList.push_back(tempList);
        }

        for (int i = 0; i < rowsForEcon; i++) {
            vector<Seat*> tempList;
            for (int j = 0; j < seatRowEcon; j++) {
                Seat *temp;
                if (j == aisleEcon) {
                    temp = new AisleSeat(this);
                } else {
                    temp = new EconSeat(basePrice, this);
                }
                tempList.push_back(temp);
            }
            SeatList.push_back(tempList);
        }
    }
}