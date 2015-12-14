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
#include <ostream>
using namespace std;

namespace Airport {
    Flight::Flight(std::string typeOfPlane) : ID(-1),startingPoint(""), destination(""), departureTime(0), arrivalTime(0), thePlane(nullptr), planeType(typeOfPlane), basePrice(0) {
        if (!planeType.empty()) {
            int numSeats = TypePlane::getNumOfSeats(planeType);
            numFirstClass = TypePlane::calcFirst(numSeats);
            numEconPlus = TypePlane::calcEconPlus(numSeats);
            numEcon = TypePlane::calcEcon(numFirstClass, numEconPlus, numSeats);
            numRows = TypePlane::getNumOfRows(planeType);
            _initSeatList();

        }
    }
    Flight::Flight(int newID, std::string typeOfPlane, time_t departTime, time_t arriveTime, double price, string end, string start)
            : ID(newID), planeType(typeOfPlane), departureTime(departTime), arrivalTime(arriveTime), basePrice(price),
              destination(end), startingPoint(start) {
        if (!planeType.empty()) {
            int numSeats = TypePlane::getNumOfSeats(planeType);
            numFirstClass = TypePlane::calcFirst(numSeats);
            numEconPlus = TypePlane::calcEconPlus(numSeats);
            numEcon = TypePlane::calcEcon(numFirstClass, numEconPlus, numSeats);
            numRows = TypePlane::getNumOfRows(planeType);
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

    int Flight::getRowsEcon() const {
        return rowsForEcon;
    }

    int Flight::getRowsFirst() const {
        return rowsForFirst;
    }

    int Flight::getRowsPlus() const {
        return rowsForPlus;
    }

    int Flight::getSeatsRowFirst() const {
        return seatRowFirst;
    }

    int Flight::getSeatsRowPlus() const {
        return seatRowPlus;
    }

    int Flight::getSeatsRowsEcon() const {
        return seatRowEcon;
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
    double Flight::getPriceOfSeat(string chosenSeat) {
        stringstream seatStream;
        seatStream.str(chosenSeat);
        int rowNum, seatNum;
        char seatChar;
        seatStream >> rowNum;
        seatStream >> seatChar;
        seatChar = toupper(seatChar);
        seatNum = static_cast<int>(seatChar - 'A');
        rowNum--;
        Seat *theSeat;
        //if (rowNum < numRows && seatNum < SeatList[rowNum].size()) {
        theSeat = SeatList[(rowNum)][seatNum];
        //}
        double thePrice = theSeat->calcPrice(30);
        cout << "the price is " << thePrice << endl;
        return thePrice;
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
        cout << "rowNum: " << rowNum << "\nSeatChar: " << seatChar << "\nSeatNum: " << seatNum << endl;
        rowNum--;
        Seat *theSeat;
        //if (rowNum < numRows && seatNum < SeatList[rowNum].size()) {
            theSeat = SeatList[(rowNum)][seatNum];
        //}
        cout << theSeat->getRow() << theSeat->getSeat() << endl;
        return bookFlight(passenger, theSeat);
    }
    string Flight::getTypeOfPlane() const {
        return planeType;
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
        vector<vector<Seat*>>::iterator vectorIter;
        int i = 0;
        int firstSpacer = 0;
        int plusSpacer = 0;
        for (int k = 0; k < (seatRowEcon - seatRowPlus); k++) {
            plusSpacer++;
        }
        for (int k=0; k<(seatRowEcon - seatRowFirst); k++) {
            firstSpacer++;
        }
        firstSpacer = firstSpacer * 2 + 1;
        plusSpacer = plusSpacer * 2 + 1;
        for (vectorIter = SeatList.begin(); vectorIter != SeatList.end(); ++vectorIter) {
            int j = 0;
            vector<Seat*>::iterator seatIter;
            if (i == 0) {
                cout << "First Class" << endl;
            } else if (i == rowsForFirst) {
                cout << "Econonmy Plus" << endl;
            } else if (i == (rowsForFirst + rowsForPlus)) {
                cout << "Economy" << endl;
            }
            cout << left << "Row "  << setw(4) << right<< (i+1) << ": ";
            //cout << setw(seatRowEcon * 3 + 2) << left;
            for (seatIter = vectorIter->begin(); seatIter != vectorIter->end(); ++seatIter) {
                (*seatIter)->printSeat();
                if (i < rowsForFirst && j==aisleFirst) {
                    cout << setw(firstSpacer);
                } else if ( i >= rowsForFirst && i < (rowsForFirst + rowsForPlus) && j==aislePlus){
                    cout << setw(plusSpacer);
                }
                j++;
            }
            cout << endl;
            i++;
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
        //TODO make another method that prints a plane ID too
        //cout << setw(40) << left << "Plane ID: " << right << thePlane->getId() << endl;
        cout << setw(40) << left << "Starting Seat Price: " << right << basePrice << endl;
        cout << setw(40) << left << "Total Number of Seats: " << right << (numFirstClass + numEcon + numEconPlus) << endl;
        cout << setw(40) << left << "->First Class Seats: " << right << numFirstClass << endl;
        cout << setw(40) << left << "->Economy Plus Seats: " << right << numEconPlus << endl;

        cout << setw(40) << left << "->Economy Seats: " << right << numEcon << endl;

        cout << setw(40) << left << "Flight Starting Location: " << right << startingPoint << endl;
        cout << setw(40) << left << "Flight Destination: " << right << destination << endl;
        cout << setw(40) << left << "Departure Time: " << right << ctime(&departureTime) << endl;
        cout << setw(40) << left << "Arrival Time: " << right << ctime(&arrivalTime) << endl;
    }
    void Flight::_initSeatList() {
        rowsForEcon = numRows/2;
        rowsForFirst = floor((double)rowsForEcon/2);
        rowsForPlus = ceil((double)rowsForEcon/2);
        seatRowFirst = ceil((double)numFirstClass/rowsForFirst);
        seatRowPlus = ceil((double)numEconPlus/rowsForPlus);
        seatRowEcon = ceil((double)numEcon/rowsForEcon);
        aisleFirst = ceil((double)seatRowFirst/2);
        aislePlus = ceil((double)seatRowPlus/2);
        aisleEcon = ceil((double)seatRowEcon/2);

        //need to increment numSeats to add in aisle
        seatRowFirst++;
        seatRowPlus++;
        seatRowEcon++;

        numFirstClass = rowsForFirst * seatRowFirst - rowsForFirst;
        numEconPlus = rowsForPlus * seatRowPlus - rowsForPlus;
        numEcon = rowsForEcon * seatRowEcon - rowsForEcon;

        for (int i = 0; i < rowsForFirst; i++) {
            vector<Seat*> tempList;
            for (int j = 0; j < seatRowFirst; j++) {
                Seat *temp;
                if (j == aisleFirst) {
                    temp = new AisleSeat(this);
                } else {
                    temp = new FirstClass(basePrice, this);
                }
                temp->setRow(i);
                temp->setSeat((static_cast<char>(j + 'A')));
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
                temp->setRow(i + rowsForFirst);
                temp->setSeat((static_cast<char>(j + 'A')));
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
                temp->setRow(i + rowsForFirst + rowsForPlus);
                temp->setSeat((static_cast<char>(j + 'A')));
                tempList.push_back(temp);
            }
            SeatList.push_back(tempList);
        }
    }

    void Flight::writePlaneFile(ostream &flightFile, ostream &seatFile) {
        flightFile << "flight\n" << ID << endl;
        flightFile << basePrice << endl;
        flightFile << startingPoint << endl;
        flightFile << destination << endl;
        flightFile << planeType << endl;
        flightFile << departureTime << " " << arrivalTime << endl;
        if (thePlane != nullptr) {
            flightFile << thePlane->getId() << endl;
        }
        seatFile << "flight " << ID << endl;
        vector<vector<Seat*>>::iterator vectorIter;
        for (vectorIter = SeatList.begin(); vectorIter != SeatList.end(); ++vectorIter){
            vector<Seat*>::iterator seatIter;
            for (seatIter = (*vectorIter).begin(); seatIter !=(*vectorIter).end(); seatIter++ ) {
                (*seatIter)->writeToFile(seatFile);
            }
        }
        seatFile << "endFlight" << endl;
        flightFile << "endFlight" << endl;

    }
}