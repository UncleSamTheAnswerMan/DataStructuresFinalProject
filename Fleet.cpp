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

        for (int i=0;i<Planes.size();i++) {
            if (Planes[i]->getId() == oldPlane->getId()) {
                Planes.erase(Planes.begin()+i);
            }
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

    void Fleet::writePlanes(ostream &planeFile) {
        vector<Plane*>::iterator iter;
        for (iter = Planes.begin(); iter != Planes.end(); ++iter) {
            (*iter)->writePlane(planeFile);
        }
    }
}
