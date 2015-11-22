//
// Created by thisguy on 11/22/15.
//
#include <iostream>
#include "Fleet.h"
using namespace std;
namespace Airport {
    Fleet::Fleet() : homePort(nullptr) {}
    Fleet::Fleet(Aiport* port) : homePort(port) {}

    void addPlane(Plane newPlane) {
        Planes.push_back(newPlane);
    }
    void delPlane(Plane oldPlane) {
        for (auto it=begin(Planes); it != end(Planes); ++it)
            if ((*it)->getId() == oldPlane->getId()) {
                Planes.erase(it);
            }
    }

}
