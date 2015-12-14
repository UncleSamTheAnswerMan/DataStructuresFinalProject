#include <iostream>
#include "Port.h"
#include "Menu.h"
#include "Fleet.h"
#include <string>

using namespace Airport;
using namespace std;

int main() {
    Port* a = new Port();
    Menu* m = new Menu(a);
    m->login();
    return 0;
}