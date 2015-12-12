#include <iostream>
#include "Port.h"
#include "Menu.h"
#include "Fleet.h"
#include <string>

using namespace Airport;
using namespace std;

int main() {
    string thisString = "hi";
    cout << thisString;
    Port* a = new Port();
    Menu* m = new Menu(a);
    int flightId = m->createFlightId();
    Plane* thePlane = new Plane();
    time_t depTime = m->getTime();
    time_t arriveTime = m->getTime();
    double thePrice = m->userBasePrice();
    string start = "msp";
    string end = "dfw";
    Flight* newFlight = new Flight(flightId,thePlane,depTime,arriveTime,thePrice,start,end);
    newFlight->printFlight();
    //m->textGUI();
    return 0;
}