#pragma once
#include<iostream>
#include<random>
#include<time.h>

using namespace std;

// We created a class for the Box with three parameters, l,w,h.
class Box{
    private:
        int length;
        int width;
        int height;
    public:
        Box(){ // In this constructor, the box length, width and height are being randomized with in the range of 30.
            length = (rand() %25) + 5;
            width = (rand() %25) + 5;
            height = (rand() %25) + 5;
        }
        int volume(){ // This function gives us the volume of the box that was generated, it will be called to print out the volume.
            return length * width * height;
        }
        void Load(){ // This function is basically just printing out the dimensions of the box that was created, it is called inside the load and unload function.
            std::cout << ", Length: "<<length<<", Width: "<<width<<", Height: "<<height<<endl;
        }
};
