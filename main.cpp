#include <iostream>
#include "Port.h"
#include "Menu.h"
#include "Fleet.h"

using namespace Airport;
using namespace std;

int main() {
    Port* a = new Port();
    Menu* m = new Menu(a);
    m->textGUI();
    return 0;
}