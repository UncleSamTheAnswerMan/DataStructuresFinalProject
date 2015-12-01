//
// Created by thisguy on 11/22/15.
//

#include "Itinerary.h"
namespace Airport {
    Itinerary::Itinerary() { }

    int Itinerary::addFlight(const Flight *flightToAdd) { //TODO add error checking to prevent paradoxes in the time-space continuum
        vector<Flight*>::iterator iter;
        for(iter = flightList.begin(); iter!=flightList.end(); iter++){
            if ((*iter)->getID() == flightToAdd->getID()) {
                cout << "Flight already added. What were you thinking?" << endl;
                return -1;
            }
        }
        flightList.push_back(flightToAdd);
        return 0;
    }

    int Itinerary::deleteFlight(const Flight *flightToDelete) {
        vector<Flight*>::iterator iter;
        for(iter = flightList.begin(); iter!=flightList.end(); iter++){
            if ((*iter)->getID() == flightToDelete->getID()) {
                flightList.erase(iter);
                return 0;
            }
        }
        cout << "Flight was not found, unable to delete. Try again with better input.";
        return -1;
    }

    Flight* Itinerary::findFlightByTime(const time_t timeToFind) {
        vector<Flight*>::iterator iter;
        for (iter = flightList.begin(); iter!=flightList.end(); iter++){
            if ((*iter)->getDepart() == timeToFind) {
                return (*iter);
            }
        }
        cout<<"Flight not found..." << endl;
        return nullptr;
    }

    Flight* Itinerary::findFlightByID(const int flightID) {
        vector<Flight*>::iterator iter;
        for(iter = flightList.begin(); iter!=flightList.end(); iter++) {
            if ((*iter)->getID() == flightID) {
                return (*iter);
            }
        }
        cout << "Flight not found..." << endl;
        return nullptr;
    }

    void Itinerary::showAllFlights() const {
        vector<Flight*>::iterator iter;
        for(iter = flightList.begin(); iter!=flightList.end(); iter++){
            (*iter)->printFlight();
        }
    }

    void Itinerary::showNextFlight() const{
        Flight* nextFlight = flightList[0];
        vector<Flight*>::iterator iter;
        for(iter = flightList.begin(); iter!=flightList.end(); iter++) {
            if ((*iter)->getDepart() < nextFlight->getDepart()) {
                nextFlight = (*iter);
            }
        }

        nextFlight->printFlight();
    }
}