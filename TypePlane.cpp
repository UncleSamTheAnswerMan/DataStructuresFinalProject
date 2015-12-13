//
// Created by thisguy on 11/22/15.
//

#include "TypePlane.h"
#include <iostream>
using namespace std;

namespace Airport {
//    TypePlane::TypePlane(std::string planeType) : typeOfPlane(planeType) {
//
//    }

    void TypePlane::printTypes() {
        cout << "1 A380" << endl;
        cout << "2 A330" << endl;
        cout << "3 C130" << endl;
        cout << "4 Boeing747" << endl;
        cout << "5 Boeing 737" << endl;
        cout << "6 L1011" << endl;
    }
    int TypePlane::getNumOfSeats(std::string planeType) {
        cout << planeType << endl;
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

    int TypePlane::getNumOfRows(std::string planeType) {
        if (planeType.compare("A380")) {
            return 900/10;
        } else if (planeType.compare("A330")) {
            return 256/8;
        } else if (planeType.compare("C130")) {
            return 90/5;
        } else if (planeType.compare("Boeing747")) {
            return 336/8;
        } else if (planeType.compare("Boeing737")) {
            return 168/6;
        } else if (planeType.compare("L1011")) {
            return 192/6;
        } else {
            return -1;
        }
    }

//    std::string TypePlane::getTypeOfPlane() {
//        return typeOfPlane;
//    }

    int TypePlane::calcEcon(int firstClass, int econPlus, int total) {
        return (total - firstClass - econPlus);
    }

    int TypePlane::calcFirst(int total) {
        return (int)(total *.1);
    }

    int TypePlane::calcEconPlus(int total) {
        return (int)(total *.2);
    }




}