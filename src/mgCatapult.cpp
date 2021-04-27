#include <iostream>
#include <math.h>
#include "mgCatapult.h"

#define _USE_MATH_DEFINES
using namespace std;



void mg_init_cat(mgCatapult* catapulta){
    cout << "define wheel radius: ";
    cin >> catapulta -> rad;
    cout << "define bed hight: ";
    cin >> catapulta -> hbase;
    cout << "define box hight: ";
    cin >> catapulta -> hbox;
    cout << "define arm length: ";
    cin >> catapulta -> arm;
    cout << "define launch angle: ";
    cin >> catapulta -> alfa;

    void mg_check(mgCatapult* catapulta);
    int controllo = 0;
    if (controllo == 0){
        cout << "The set values are correct, a svg file can be created" << endl;
    }
    else if (controllo == 1){
        cout << "All values mast be <= 0, try again" << endl;
    }
}

void mg_check(mgCatapult* catapulta){
    int val;
    float alfamax = 90 + atan2f(catapulta->hbox , 500 ) * 180 / M_PI;
    float hbmax = 2*catapulta->rad;
    if (catapulta -> rad > 0 && 
        catapulta -> hbase > 0 &&
        catapulta -> hbox > 0 &&
        catapulta -> alfa > 0 &&
        catapulta -> arm > 0 )
        val=0;
    else
        val=1;  //valori negativi 
    if (catapulta->alfa > alfamax){
        val=2;
        cout << "the angle of launch is too big" << endl;
    }
    if (catapulta->hbase > hbmax)
        val=3;
        cout << "either the radius is too small or the hight of the base iss too big, change at least one " << endl;
}