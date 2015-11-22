//
// Created by thisguy on 11/22/15.
//

#include "TypePlane.h"

namespace Airport {
    TypePlane::TypePlane(std::string planeType) : typeOfPlane(planeType) {

    }

    int TypePlane::getNumOfSeats() {
        if (typeOfPlane.compare("A380")) {
            return 900;
        } else if (typeOfPlane.compare("A330")) {
            return 253;
        } else if (typeOfPlane.compare("C130")) {
            return 92;
        } else if (typeOfPlane.compare("Boeing747")) {
            return 330;
        } else if (typeOfPlane.compare("Boeing737")) {
            return 162;
        } else if (typeOfPlane.compare("L1011")) {
            return 190;
        } else {
            return -1;
        }
    }

    std::string TypePlane::getTypeOfPlane() {
        return typeOfPlane;
    }
}