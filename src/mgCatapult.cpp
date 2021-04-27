#include <iostream>
#include <math.h>
#include <fstream>
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

string mg_catSVG(mgCatapult* catapulta){
    string cat;
    cat = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">\n\n";
    cat += "<rect x=\"0\" y=\"0\" width=\"800\" height=\"600\" style=\"fill:white;stroke:white;stroke-width:2\" />\n";
    cat += "<rect x=\"50\" y=\"" + to_string(390 - catapulta->hbase) + "\" width=\"500\" height=\"20\" style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n\n";
    cat += "<circle cx=\"150\" cy=\"350\" r=\"" + to_string(catapulta->rad) + "\" stroke=\"black\" stroke-width=\"9\" fill=\"#a5532a\" />\n\n";
    cat += "<g transform=\"rotate(" + to_string(catapulta->alfa) + "," + to_string(390 - catapulta->hbase + (catapulta->hbox/2)) + ",290)\">\n";
    cat += "<rect x=\"" + to_string(400 - catapulta->arm) + "\" y=\"280\" width=\"" + to_string(catapulta->arm) + "\" height=\"20\" 	style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n";
    cat += "<rect x=\"" + to_string(400 - 20 - catapulta->arm) + "\" y=\"280\" width=\"80\" height=\"35\" 	style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n";
    cat += "</g>\n";
    cat += "<rect x=\"300\" y=\"" + to_string(390 - catapulta->hbase - (catapulta->hbox)/2) + "\" width=\"200\" height=\"60\" style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n";
    cat += "<circle cx=\"450\" cy=\"350\" r=\"" + to_string(catapulta->rad) + "\" stroke=\"black\" stroke-width=\"9\" fill=\"#a5532a\" />\n";
    cat += "<circle cx=\"" + to_string(390 - catapulta->hbase + (catapulta->hbox/2)) + "\" cy=\"290\" r=\"3\" stroke=\"black\" stroke-width=\"5\" fill=\"white\" />\n";
    cat += "</svg>\n";

    return cat;
}

void mg_filew(string cat){

    if(cat == "") {
        cout << "Something went werong during the svg generation";
    }
    if(cat != ""){
        string nome;

        cout << "Write file name (es: catcatapult.svg)" << endl;
        cin >> nome;

        // Create and open a text file
        ofstream MyFile(nome);

        // Write to the file
        MyFile << cat;

        // Close the file
        MyFile.close();
    }
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