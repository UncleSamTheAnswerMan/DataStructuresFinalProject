//
// Created by thisguy on 11/22/15.
//

#ifndef DATASTRUCTURESFINALPROJECT_TYPEPLANE_H
#define DATASTRUCTURESFINALPROJECT_TYPEPLANE_H
#include <iostream>

namespace Airport {
    class TypePlane {
    public:
        static void printTypes();
        //TypePlane(std::string planeType);
        static int getNumOfSeats(std::string planeType);
        //std::string getTypeOfPlane();
        static int calcEcon(int firstClass, int EconPlus, int total);
        static int calcFirst(int total);
        static int calcEconPlus(int total);
        static int getNumOfRows(std::string planeType);
    private:
        //std::string typeOfPlane;

    };
}
#endif //DATASTRUCTURESFINALPROJECT_TYPEPLANE_H
