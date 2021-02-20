#pragma once
#include <iostream>
#include "box.hpp"

class Truck
{
    private:
        string driver;
        int petrol;
        int money;
        int fullMileage;
        int emptyMileage;
        Box box[10];
    public:
        Truck(string drv, int petr, int mon, int fullm, int emptym){
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
        bool cost(){
            float total_petrol = petrol + money  / 2.73;
            if (total_petrol > 50) total_petrol = 50;
            float petrol_required = 60 / fullMileage + 60 / emptyMileage;
            return petrol_required <= total_petrol; 
        }
};

