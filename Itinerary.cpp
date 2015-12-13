//
// Created by thisguy on 11/22/15.
//

#include "Itinerary.h"
#include <ostream>
using std::vector;
namespace Airport {
    Itinerary::Itinerary() : flightList(){ }

    int Itinerary::addFlight(Flight *flightToAdd) { //TODO add error checking to prevent paradoxes in the time-space continuum
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

    int Itinerary::deleteFlight(Flight *flightToDelete) {
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
        for (iter = flightList.begin(); iter!=flightList.end(); ++iter){
            if ((*iter)->getDepart() == timeToFind) {
                return (*iter);
            }
        }
        cout<<"Flight not fItineraryound..." << endl;
        return nullptr;
    }

    Flight* Itinerary::findFlightByID(const int flightID) {
        vector<Flight*>::iterator iter;
        for(iter = flightList.begin(); iter!=flightList.end(); ++iter) {
            if ((*iter)->getID() == flightID) {
                return (*iter);
            }
        }
        cout << "Flight not found..." << endl;
        return nullptr;
    }

    void Itinerary::showAllFlights() {
        vector<Flight*>::iterator iter;
        for(iter = flightList.begin(); iter!=flightList.end(); ++iter){
            (*iter)->printFlight();
        }
    }

    void Itinerary::showNextFlight() {
        Flight* nextFlight = flightList[0];
        vector<Flight*>::iterator iter;
        for(iter = flightList.begin(); iter!=flightList.end(); ++iter) {
            if ((*iter)->getDepart() < nextFlight->getDepart()) {
                nextFlight = (*iter);
            }
        }

        nextFlight->printFlight();
    }

    void Itinerary::writeItinerary(ostream &planeOutput) {
        planeOutput << "itinerary" << endl;
        vector<Flight*>::iterator iter;
        if (!flightList.empty()) {
            planeOutput << flightList[0]->getID() << endl;
            for (iter = flightList.begin(); iter != flightList.end(); ++iter) {
                planeOutput << (*iter)->getID() << "\n";
            }
        }
        planeOutput << "endItinerary" << endl;
    }
}