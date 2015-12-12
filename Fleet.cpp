//
// Created by thisguy on 11/22/15.
//
#include <iostream>
#include "Fleet.h"
#include "Port.h"
#include "Plane.h"

using namespace std;
namespace Airport {
    Fleet::Fleet() : homePort(nullptr) {}
    Fleet::Fleet(Port *port) : homePort(port) {}

    void Fleet::addPlane(Plane* newPlane) {
        Planes.push_back(newPlane);
    }
    void Fleet::deletePlane(Plane* oldPlane) {
        for (vector<Plane*>::iterator it=begin(Planes); it != end(Planes); ++it)
            if ((*it)->getId() == oldPlane->getId()) {
                Planes.erase(it);
            }

    }
    int Fleet::getFleetSize() const {
        return Planes.size();
    }
    void Fleet::showFleet () {
        for (int  i=0; i<Planes.size(); i++)
        {
            Planes[i]->printPlane();
        }
    }
    Plane* Fleet::getPlaneByIndex(int i) {
        return Planes[i];
    }
    Plane* Fleet::getPlaneById(int id) {
        for (int  i=0; i<Planes.size(); i++)
        {
            if (Planes[i]->getId() == id) {
                return Planes[i];
            }
        }

    }

}
