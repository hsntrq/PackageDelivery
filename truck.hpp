#pragma once
#include <iostream>
#include "box.hpp"

class Truck
{
    public:
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
        float cost();
};

