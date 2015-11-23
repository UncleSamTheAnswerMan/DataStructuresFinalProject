//
// Created by thisguy on 11/22/15.
//

#include "TypePlane.h"

namespace Airport {
//    TypePlane::TypePlane(std::string planeType) : typeOfPlane(planeType) {
//
//    }

    static int TypePlane::getNumOfSeats(std::string planeType) {
        if (planeType.compare("A380")) {
            return 900;
        } else if (planeType.compare("A330")) {
            return 250;
        } else if (planeType.compare("C130")) {
            return 90;
        } else if (planeType.compare("Boeing747")) {
            return 330;
        } else if (planeType.compare("Boeing737")) {
            return 160;
        } else if (planeType.compare("L1011")) {
            return 190;
        } else {
            return -1;
        }
    }

    static int TypePlane::getNumOfRows(std::string planeType) {
        if (planeType.compare("A380")) {
            return 900/10;
        } else if (planeType.compare("A330")) {
            return 250/8;
        } else if (planeType.compare("C130")) {
            return 90/5;
        } else if (planeType.compare("Boeing747")) {
            return 330/8;
        } else if (planeType.compare("Boeing737")) {
            return 160/7;
        } else if (planeType.compare("L1011")) {
            return 190/6;
        } else {
            return -1;
        }
    }

//    std::string TypePlane::getTypeOfPlane() {
//        return typeOfPlane;
//    }

    void TypePlane::calcSeats(int *firstClass, int *econPlus, int *econ, int total) {
        *firstClass = total * .1;
        *econPlus = total * .2;
        *econ = total - *firstClass - *econPlus;
    }


}