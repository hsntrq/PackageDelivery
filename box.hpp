#pragma once
#include<iostream>
#include<random>
#include<time.h>

using namespace std;

class Box{
    private:
        int length;
        int width;
        int height;
    public:
        Box(){
            srand(time(0));
            length = (rand() %25) + 5;
            width = (rand() %25) + 5;
            height = (rand() %25) + 5;
        }
        int volume(){
            return length * width * height;
        }
};
