#pragma once
#include <iostream>
#include "box.hpp"
#include <fstream>
#include <string>
#include <sstream>

class Truck
{
    private:
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
            total_petrol = petrol + money  / 2.73;
            if (total_petrol > 50) total_petrol = 50;
            petrol_required = 60.0 / fullMileage + 60.0 / emptyMileage;
        }

        void load(){
            std::cout<<"Loading the Boxes"<<endl;
            for (int i=0; i<10;i++) {
                std::cout<<"Box no. "<<i+1;
                box[i].Load();
            }
        }
        void unload(){
            std::cout <<"Unloading the Boxes"<<endl;
            for (int i=0; i<10; i++){
                std::cout<<"Box no. "<<i+1;
                box[i].Load();
                std::cout<<"Volume: "<<box[i].volume()<<endl;
            }
        }
        float cost(){
            if (petrol_required <= total_petrol){
                if (petrol_required-petrol >= 0)
                    return 2.73*(petrol_required-petrol);
                else    
                    return 0;
            }
            return -1;
        
        }
        void update(){
            if (petrol_required <= total_petrol){
                if (petrol_required-petrol >= 0){
                    money = money - 2.73*(petrol_required-petrol);
                    petrol = total_petrol - petrol_required;
                }
            }
        }
        bool Trip(){
            if (petrol_required <= total_petrol)
                if (money >= 2.73*(petrol_required-petrol))
                    return true;
            return false;
        }
        void Record(ofstream& output_file){
            output_file<<driver<<endl;
            output_file<<petrol<<endl;
            output_file<<money<<endl;
            output_file<<emptyMileage<<endl;
            output_file<<fullMileage<<endl;
        }
};

