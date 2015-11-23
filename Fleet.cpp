//
// Created by thisguy on 11/22/15.
//
#include <iostream>
#include "Fleet.h"
#include "Airport.h"
#include "Plane.h"

using namespace std;
namespace Airport {
    Fleet::Fleet() : homePort(nullptr) {}
    Fleet::Fleet(Airport *port) : homePort(port) {}

    void Fleet::addPlane(Plane newPlane) {
        Planes.push_back(newPlane);
    }
    void Fleet::delPlane(Plane oldPlane) {
        for (auto it=begin(Planes); it != end(Planes); ++it)
            if ((*it)->getId() == oldPlane->getId()) {
                Planes.erase(it);
            }
    }

}
