#pragma once
#include <iostream>
#include "box.hpp"

class Truck
{
    private:
        string driver;
        float petrol;
        int money;
        float fullMileage;
        float emptyMileage;
        Box box[10];
    public:
        Truck(string drv, float petr, int mon, float fullm, float emptym){
            driver = drv;
            petrol = petr;
            money = mon;
            fullMileage = fullm;
            emptyMileage = emptym;
        }

        void load(){
            for (int i = 0; i < 10; i++) std::cout<<"Box #"<<i<<": "<<box[i].volume()<<'\n';
        }
        void unload(){
            for (int i = 0; i < 10; i++) std::cout<<"Box #"<<i<<": "<<box[i].volume()<<'\n';
        }
        float cost(){
            float total_petrol = petrol + money  / 2.73;
            if (total_petrol > 50) total_petrol = 50;
            float petrol_required = 60.0 / fullMileage + 60.0 / emptyMileage;
            if (petrol_required <= total_petrol){
                if (petrol_required-petrol >= 0)
                    return 2.73*(petrol_required-petrol);
                else    
                    return 0;
            }
            return -1;
        }
};

