#ifndef MGMACHINE_H
#define MGMACHINE_H

#include "mgCatapult.h"
#include "Car.h"
#include <iostream>
#include <string> 
#include <fstream> 

using namespace std;

struct mgMachine
{
    mgCatapult catap;
    coca_device car;        
};

std::string mg_machineSVG(mgMachine* catcar);    // compone la stringa che fungerà da svg
bool mg_are_equal(mgMachine* machine1, mgMachine* machine2);    // controlla se le due machine sono uguali 
mgMachine* mg_newmachine();     // inizializza un nuovo oggetto mgMachine
void mg_destroyM(mgMachine* machine);   // cancella la struct 

#endif