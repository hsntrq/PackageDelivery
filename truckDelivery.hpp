#include "truck.hpp"
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;

class TruckDelivery{
public:
    vector<Truck> trucks;
public:
    void loadTrucks(){
        string T;
        string Trk[5];
        ifstream Truck_file("Drivers.txt");
        int count = 0;
        while (getline (Truck_file, T)){
            Trk[count] = T;
            count++;
            if (count == 5) {
                count = 0;
                trucks.push_back(Truck(Trk[0],stoi(Trk[1]),stoi(Trk[2]),stoi(Trk[3]),stoi(Trk[4])));
            }
        }
    }
    void calculateCost();
    void makeJourney();
    void unloadTrucks();
};
	
