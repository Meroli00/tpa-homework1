#include <iostream>
#include <math.h>
#include <mgCatapult.h>

#define _USE_MATH_DEFINES
using namespace std;

int mg_check(mgCatapult* catapulta){
    int val =0 ;
    float alfamax = 90 + atan2f(catapulta->hbox , 500 ) * 180 / M_PI;
    float hbmax = 2*(catapulta->rad);
    if (catapulta -> rad > 0 && 
        catapulta -> hbase > 0 &&
        catapulta -> hbox > 0 &&
        catapulta -> alfa > 0 &&
        catapulta -> arm > 0 )
    {val=1;}
    
    
    if (catapulta->alfa > alfamax){
        val=2;
        cout << "the angle of launch is too big, it should be less than " << alfamax << endl;
    }

    if (catapulta->hbase > hbmax){
        val=3;
        cout << "either the radius is too small or the hight of the base iss too big, change at least one " << endl;}
    return val;
}

string mg_ctSVG(){



}




void mg_init_cat(mgCatapult* catapulta){
    while(true){
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

        if ( mg_check(catapulta) ){
            cout << "The set values are correct, a .svg file can be created" << endl;
            mg_catSVG(catapulta);
            return;
        }
    }
}