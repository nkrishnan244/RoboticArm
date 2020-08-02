#include "simulation.hpp"
#include <iostream>

using namespace std;

int main()
{
    Simulation sim;
    while(!sim.getWindowShouldClose())
    {
        sim.update();
    }
    cout << "hello world" << "\n";
    return 0;
}