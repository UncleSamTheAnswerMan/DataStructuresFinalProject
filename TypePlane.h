//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_TYPEPLANE_H
#define DATASTRUCTURESFINALPROJECT_TYPEPLANE_H
#include <iostream>

namespace Airport {
    class TypePlane {
    public:
        TypePlane(std::string planeType);
        int getNumOfSeats();
        std::string getTypeOfPlane();
        static void calcSeats(int* firstClass, int* EconPlus, int* Econ, int total);
    private:
        std::string typeOfPlane;

    };
}
#endif //DATASTRUCTURESFINALPROJECT_TYPEPLANE_H
