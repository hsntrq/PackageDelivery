#pragma once
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
            for (int i = 0; i < 10; i++) cout<<box[i];
        }
        void unload(){
            for (int i = 0; i < 10; i++) cout<<box[i];
        }
        float cost();
};

