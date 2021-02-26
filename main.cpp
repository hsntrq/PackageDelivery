#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "truck.hpp"
#include "box.hpp"
#include "truckDelivery.hpp"
#include <fstream>

using namespace std;
int main()
{
    ofstream output_file("Trip.txt");
    TruckDelivery delivery;
    delivery.loadTrucks();
    delivery.calculateCost();
    delivery.makeJourney();
    delivery.unloadTrucks(output_file);
    return 0;
}
