#pragma once
#include <iostream>
#include "box.hpp"
#include <fstream>
#include <string>
#include <sstream>

class Truck
{
    private: // The varuables of total petrol and petrol required are made as they are being used by the functions of this class more than one times.
        string driver;
        float petrol;
        int money;
        float fullMileage;
        float emptyMileage;
        Box box[10];
        float total_petrol;
        float petrol_required;
    public:
        Truck(string drv, float petr, int mon, float fullm, float emptym){
            driver = drv;
            petrol = petr;
            money = mon;
            fullMileage = fullm;
            emptyMileage = emptym;
            total_petrol = petrol + money  / 2.73; // This is checking how much petrol can the person have including his all money.
            if (total_petrol > 50) total_petrol = 50; // This is checking if the petrol is above 50 then make it 50 maximum as it is the maximum fuel limit a truck can have.
            petrol_required = 60.0 / fullMileage + 60.0 / emptyMileage; // This is checking for how much petrol is required as the total travel distance is 60+60 miles
        }

        void load(){ // This function is showing the dimensions of all the boxes present in the truck.
            std::cout<<"Loading the Boxes"<<endl;
            for (int i=0; i<10;i++) {
                std::cout<<"Box no. "<<i+1;
                box[i].Load();
            }
        }
        void unload(){ // This function shows the volume as well as dimensions of all the boxes present inside the truck.
            std::cout <<"Unloading the Boxes"<<endl;
            for (int i=0; i<10; i++){
                std::cout<<"Box no. "<<i+1;
                box[i].Load();
                std::cout<<"Volume: "<<box[i].volume()<<endl;
            }
        }
        float cost(){ // This function is calculating the cost of the truck travel, returning 0 if it has enough petrol, otherwise returning the cost. It returns -1 if the driver doesn't have enough money to fulfil petrol requirment.   
            if (petrol_required <= total_petrol){
                if (petrol_required-petrol >= 0)
                    return 2.73*(petrol_required-petrol);
                else    
                    return 0;
            }
            return -1;
        
        }
        void update(){ // This function is updating the fuel and the money spend by the truck.
            if (petrol_required <= total_petrol){
                if (petrol_required-petrol >= 0){
                    money = money - 2.73*(petrol_required-petrol);
                    petrol = total_petrol - petrol_required;
                }
            }
        }
        bool Trip(){ // This function is basically return True when the petrol is enough and money is enough to buy the petrol otherwise it return false.
            if (petrol_required <= total_petrol)
                if (money >= 2.73*(petrol_required-petrol))
                    return true;
            return false;
        }
        void Record(ofstream& output_file){ // This function basically writes the information of each truck in the output_file.
            output_file<<driver<<endl;
            output_file<<petrol<<endl;
            output_file<<money<<endl;
            output_file<<emptyMileage<<endl;
            output_file<<fullMileage<<endl;
        }
};

