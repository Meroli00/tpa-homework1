#ifndef MGMACHINE_H
#define MGMACHINE_H

#include "C:\Users\giaco\Desktop\compito 1\include\Car.h"
#include "C:\Users\giaco\Desktop\compito 1\include\mgCatapult.h"
#include <iostream>
#include <string> 
#include <fstream> 

using namespace std;

struct mgMachine
{
    mgCatapult catap;
    coca_device car;        
};

std::string mg_deviceSVG(mgMachine* catcar);    // creates a string for a device


#endif