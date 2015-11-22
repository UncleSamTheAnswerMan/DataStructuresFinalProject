//
// Created by thisguy on 11/22/15.
//
#include <iostream>
#include "Passenger.h"
using namespace std;
namespace Airport {
    Passenger::Passenger() : firstName(""), lastName(""), ID(-1) {}
    Passenger::Passenger(string fName, string lName, int idNo) : firstName(fName), lastName(lName), ID(idNo) {}

    void Passenger::setFirstName(string newfirstName) {
        firstName = newfirstName;
    }
    string Passenger::getFirstName() {
        return firstName;
    }
    void Passenger::setLastName(string newLastName) {
        lastName = newLastName;
    }
    string Passenger::getLastName() {
        return lastName;
    }
    int Passenger::getId(){
        return ID;
    }
    void Passenger::setId(int newId) {
        ID = newId;
    }


}
