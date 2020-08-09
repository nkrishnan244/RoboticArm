#include "simulation.hpp"
#include <iostream>

using namespace std;

int main()
{
    Simulation sim;
    while(!sim.getWindowShouldClose())
    {
        sim.update();
        sim.render();
    }
    cout << "hello world" << "\n";
    return 0;
}