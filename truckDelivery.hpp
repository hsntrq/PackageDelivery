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
    void loadTrucks(){ // This function is loading the trucks data given in the Drivers.txt file by reading each line then converting those inputs, which are numbers, into integers in order to compute in other functions. It is filling the trucks vector.
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
    void calculateCost(){ // This function is calculating the cost spent by each driver, this function calls the cost() function of defined inside each truck class which is computing the cost for that truck, and then printing out the cost for each truck.
        std::cout << "Cost spent by each driver for the fuel"<<endl;
        for(int i=0; i < trucks.size(); i++)
            std::cout << "Travel cost for Truck "<<i+1<<" is: "<<trucks.at(i).cost()<<endl;
    }
    void makeJourney(){ // This function is using the "update()" function defined inside the truck class. which will update the fuel and money of each truck.
        for(int i=0; i < trucks.size(); i++)
            trucks.at(i).update();
    }
    void unloadTrucks(ofstream& output_file){ // This function is basically printing out the dimensions of boxes present inside of each truck. It is also deleting the truck which was unable to complete its journey. This function also uses the record function which writes the data of each truck in to the file.
        int j = 0;
        for (auto i = trucks.begin(); i != trucks.end(); ++i) {
            if(trucks[j].Trip()){ // This function checks whether the trip is possible or not.
                trucks[j].unload();
                trucks[j].Record(output_file);
            }
            else{
                trucks.erase(i);
            }
            j++;
        }
    }
};
	
