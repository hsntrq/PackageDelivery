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
    void calculateCost(){
        std::cout << "Cost spended by each driver for the fuel"<<endl;
        for(int i=0; i < trucks.size(); i++)
            std::cout << "Travel cost for Truck "<<i+1<<" is: "<<trucks.at(i).cost()<<endl;
    }
    void makeJourney(){
        for(int i=0; i < trucks.size(); i++)
            trucks.at(i).update();
    }
    void unloadTrucks(ofstream& output_file){
        for (int i=0; i<trucks.size(); i++){
            if(trucks[i].Trip()){
            trucks[i].unload();
            trucks[i].Record(output_file);
            }
        }
    }
};
	
