#include <math.h>
#include <iostream>
#include <string>
#include "mgCatapult.h"

#define _USE_MATH_DEFINES
using namespace std;
int val = 0;

void mg_set_rad(mgCatapult* catapulta){
    cout << "choose a new value for the wheel radius: " << endl;
    cin >> catapulta->rad;
    mg_check(catapulta);
    val=0;
}
void mg_set_hbase(mgCatapult* catapulta){
    cout << "choose a new value for the bed hight: " << endl;
    cin >> catapulta->hbase;
    mg_check(catapulta);
    val=0;
}
void mg_set_hbox(mgCatapult* catapulta){
    cout << "choose a new value for the box hight: " << endl;
    cin >> catapulta->hbox;
    mg_check(catapulta);
    val=0;
}
void mg_set_arm(mgCatapult* catapulta){
    cout << "choose a new value for the arm length: " << endl;
    cin >> catapulta->arm;
    mg_check(catapulta);
    val=0;
}
void mg_set_alfa(mgCatapult* catapulta){
    cout << "choose a new value for the launch angle: " << endl;
    cin >> catapulta->alfa;
    mg_check(catapulta);
    val=0;
}
int mg_check(mgCatapult* catapulta){
    float alfamax = 90 + atan2f(catapulta->hbox , 500 ) * 180 / M_PI;
    float hbmax = 2*(catapulta->rad);
    do{
        if (catapulta -> rad < 0){
            cout << "all values must be grater than 0" << endl;
            mg_set_rad(catapulta);
        };
        if (catapulta -> hbox < 0){
            cout << "all values must be grater than 0" << endl;
            mg_set_hbox(catapulta);
        };
        if (catapulta -> hbase < 0){
            cout << "all values must be grater than 0" << endl;
            mg_set_hbase(catapulta);
        };
        if (catapulta -> arm < 0){
            cout << "all values must be grater than 0" << endl;
            mg_set_arm(catapulta);
        };
        if (catapulta -> alfa < 0){
            cout << "all values must be grater than 0" << endl;
            mg_set_alfa(catapulta);
        };
        
        if (catapulta->alfa > alfamax){
            val=1;
            cout << "the angle of launch is too big, it should be less than " << alfamax << endl;
            mg_set_alfa(catapulta);
        };

        if (catapulta->hbase > hbmax){
            val=1;
            int k;
            cout << "either the radius is too small or the hight of the base iss too big, change at least one " << endl;
            cin >> k;
            do{
                cout << "digit [1] to modify the radius, [2] to modify the base hight" << endl;
                if (k==1){mg_set_rad(catapulta);}
                if (k==2){mg_set_hbase(catapulta);}
            }while(k!=1 & k!=2);            
        };
        return val;
    }while(val!=0);
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

void mg_file_w(string cat){

    if(cat == "") {
        cout << "Something went werong during the svg generation";
    }
    if(cat != ""){
        string filew;

        cout << "Type file name (es: catcatapult.svg)" << endl;
        cin >> filew;

        // Create and open a text file
        ofstream MyFile(filew);

        // Write to the file
        MyFile << cat;

        // Close the file
        MyFile.close();
    }
}

string mg_file_r(){

    string newstring,filer;

    cout << "Type file name (es: catcatapult.svg)" << endl;
    cin >> filer;
    // Read from the text file
    ifstream MyReadFile(filer);
    
    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, newstring)) {
        // Output the text from the file
        cout << newstring;
    }
    return newstring;
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