#include "C:\Users\giaco\Desktop\compito 1\include/mgCatapult.h"
#include "C:\Users\giaco\Desktop\compito 1\include\Car.h"
#include <math.h>
#include <iostream>
#include <string>

#define _USE_MATH_DEFINES

using namespace std;

int val = 0;

void mg_set_rad(mgCatapult* catapulta){
    cout << "choose a new value for the wheel radius: ";
    cin >> catapulta->rad;
    mg_check(catapulta);
    val=0;
}
void mg_set_hbase(mgCatapult* catapulta){
    cout << "choose a new value for the bed hight: ";
    cin >> catapulta->hbase;
    mg_check(catapulta);
    val=0;
}
void mg_set_hbox(mgCatapult* catapulta){
    cout << "choose a new value for the box hight: ";
    cin >> catapulta->hbox;
    mg_check(catapulta);
    val=0;
}
void mg_set_arm(mgCatapult* catapulta){
    cout << "choose a new value for the arm length: ";
    cin >> catapulta->arm;
    mg_check(catapulta);
    val=0;
}
void mg_set_alfa(mgCatapult* catapulta){
    cout << "choose a new value for the launch angle: " ;
    cin >> catapulta->alfa;
    mg_check(catapulta);
    val=0;
}
int mg_check(mgCatapult* catapulta){
    float alfamax = 90 + atan2f(catapulta->hbox , 700 ) * 180 / 3.14;
    float hbmax = 2*(catapulta->rad);
    do{
        if (catapulta -> rad < 20){
            cout << "the radius must be grater than 20, otherwise the catapult would touch the flor" << endl;
            mg_set_rad(catapulta);
        };
        if (catapulta -> rad > 100){
            cout << "the radius is too big (max value = 80)" << endl;
            mg_set_rad(catapulta);
        };
        if (catapulta -> hbox < 0){
            cout << "all values must be grater than 0" << endl;
            mg_set_hbox(catapulta);
        };
        if (catapulta -> hbox > 100){
            cout << "the hight of the box is too big (max value = 100)" << endl;
            mg_set_hbox(catapulta);
        };
        if (catapulta -> hbase < catapulta->rad ){
            cout << "the hight of the base must be grater than the wheel radius" << endl;
            mg_set_hbase(catapulta);
        };
        if (catapulta -> arm < 100){
            cout << "the arm must be a bit longer than its object holder (min value = 100)" << endl;
            mg_set_arm(catapulta);
        };
        if (catapulta -> arm > 500){
            cout << "the arm can't be longer than the base (max value = 500)" << endl;
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
            cout << "either the radius is too small or the the base is too high, change at least one parameter " << endl;            
            do{
                cout << "digit [1] to modify the radius, [2] to modify the base hight" << endl;
                cin >> k;
                if (k==1){mg_set_rad(catapulta);}
                if (k==2){mg_set_hbase(catapulta);}
            }while(k!=1 & k!=2);      
        k=0;      
        };
        return val;
    }while(val!=0);
}

string mg_catSVG(mgCatapult* catapulta){
    string cat;
    cat = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">\n\n"; // intestazione
    cat += "<rect x=\"0\" y=\"0\" width=\"800\" height=\"600\" style=\"fill:white;stroke:white;stroke-width:2\" />\n"; // sfondo bianco
    cat += "<rect x=\"250\" y=\"" + to_string(450 + catapulta->rad - catapulta->hbase) + "\" width=\"500\" height=\"20\" style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n\n"; // base
    cat += "<g transform=\"rotate(" + to_string( 90 - catapulta->alfa) + ",600," + to_string(450 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + ")\">\n"; // sdr ruotato
    cat += "<rect x=\"" + to_string(610 - catapulta->arm) + "\" y=\"" + to_string(440 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + "\" width=\"" + to_string(catapulta->arm) + "\" height=\"20\" 	style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n"; // braccio
    cat += "<rect x=\"" + to_string(610 - catapulta->arm) + "\" y=\"" + to_string(425 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + "\" width=\"80\" height=\"35\" 	style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n"; // estremita braccio
    cat += "</g>\n";
    cat += "<rect x=\"500\" y=\"" + to_string(450 + catapulta->rad - catapulta->hbase - catapulta->hbox) + "\" width=\"200\" height=\"" + to_string(catapulta->hbox) + "\" style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n";// cassone
    cat += "<circle cx=\"350\" cy=\"450\" r=\"" + to_string(catapulta->rad) + "\" stroke=\"black\" stroke-width=\"9\" fill=\"#a5532a\" />\n\n"; // ruota sx
    cat += "<circle cx=\"650\" cy=\"450\" r=\"" + to_string(catapulta->rad) + "\" stroke=\"black\" stroke-width=\"9\" fill=\"#a5532a\" />\n"; // ruota dx
    cat += "<circle cx=\"600\" cy=\"" + to_string(450 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + "\" r=\"3\" stroke=\"black\" stroke-width=\"5\" fill=\"white\" />\n"; // perno del braccio
    cat += "</svg>\n";

    return cat;
}

string mg_catSVG_quotato(mgCatapult*catapulta){
    string cat;
    //oggetti
    cat = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">\n\n"; // intestazione
    cat += "<rect x=\"0\" y=\"0\" width=\"800\" height=\"600\" style=\"fill:white;stroke:white;stroke-width:2\" />\n"; // sfondo bianco
    cat += "<rect x=\"250\" y=\"" + to_string(450 + catapulta->rad - catapulta->hbase) + "\" width=\"500\" height=\"20\" style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n\n"; // base
    cat += "<g transform=\"rotate(" + to_string( 90 - catapulta->alfa) + ",600," + to_string(450 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + ")\">\n"; // sdr ruotato
    cat += "<rect x=\"" + to_string(610 - catapulta->arm) + "\" y=\"" + to_string(440 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + "\" width=\"" + to_string(catapulta->arm) + "\" height=\"20\" 	style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n"; // braccio
    cat += "<rect x=\"" + to_string(610 - catapulta->arm) + "\" y=\"" + to_string(425 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + "\" width=\"80\" height=\"35\" 	style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n"; // estremita braccio
    cat += "</g>\n";
    cat += "<rect x=\"500\" y=\"" + to_string(450 + catapulta->rad - catapulta->hbase - catapulta->hbox) + "\" width=\"200\" height=\"" + to_string(catapulta->hbox) + "\" style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n";// cassone
    cat += "<circle cx=\"350\" cy=\"450\" r=\"" + to_string(catapulta->rad) + "\" stroke=\"black\" stroke-width=\"9\" fill=\"#a5532a\" />\n\n"; // ruota sx
    cat += "<circle cx=\"650\" cy=\"450\" r=\"" + to_string(catapulta->rad) + "\" stroke=\"black\" stroke-width=\"9\" fill=\"#a5532a\" />\n"; // ruota dx
    cat += "<circle cx=\"600\" cy=\"" + to_string(450 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + "\" r=\"3\" stroke=\"black\" stroke-width=\"5\" fill=\"white\" />\n"; // perno del braccio

    //quotature
    cat += "<g transform=\"rotate(" + to_string( 90 - catapulta->alfa) + ",600," + to_string(450 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + ")\">\n"; 
    cat += "<line x1=\"" + to_string(610 - catapulta->arm) + "\" y1=\"" + to_string(410 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + "\" x2=\"610\" y2=\"" + to_string(410 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + "\" style=\"stroke:rgb(0,0,0);stroke-width:1\" />\n";
    cat += "<text x=\"" + to_string(570 - catapulta->arm/2) + "\" y=\"" + to_string(400 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + "\" fill=\"black\">" + to_string(catapulta->arm)  + " cm" +  "</text>\n";
    cat += "</g>\n";
    cat += "<text x=\"630\" y=\"" + to_string(400 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + "\" fill=\"black\">" + to_string(catapulta->alfa)  + " gradi" +  "</text>\n";
    cat += "<line x1=\"200\" y1=\"" + to_string(450 + catapulta->rad - catapulta->hbase) + "\" x2=\"200\" y2=\"" + to_string(450 + catapulta->rad) + "\" style=\"stroke:rgb(0,0,0);stroke-width:1\" />\n";
    cat += "<text x=\"100\" y=\"" + to_string(450 + catapulta->rad - catapulta->hbase/2) + "\" fill=\"black\">" + to_string(catapulta->hbase)  + " cm" +  "</text>\n";
    cat += "<line x1=\"180\" y1=\"" + to_string(450 + catapulta->rad - catapulta->hbase - (catapulta->hbox)) + "\" x2=\"180\" y2=\"" + to_string(450 + catapulta->rad - catapulta->hbase) + "\" style=\"stroke:rgb(0,0,0);stroke-width:1\" />\n";
	cat += "<text x=\"80\" y=\"" + to_string(450 + catapulta->rad - catapulta->hbase - catapulta->hbox/2) + "\" fill=\"black\">" + to_string(catapulta->hbox) + " cm" +   "</text>\n";
    cat += "</svg>\n";

    return cat;
}
/*
string mg_deviceSVG(mgCatapult* catapulta, string svg){
    string cat;
    //catapulta
    cat = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">\n\n"; // intestazione
    cat += "<rect x=\"0\" y=\"0\" width=\"800\" height=\"600\" style=\"fill:white;stroke:white;stroke-width:2\" />\n"; // sfondo bianco
    cat += "<rect x=\"250\" y=\"" + to_string(450 + catapulta->rad - catapulta->hbase) + "\" width=\"500\" height=\"20\" style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n\n"; // base
    cat += "<g transform=\"rotate(" + to_string( 90 - catapulta->alfa) + ",600," + to_string(450 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + ")\">\n"; // sdr ruotato
    cat += "<rect x=\"" + to_string(610 - catapulta->arm) + "\" y=\"" + to_string(440 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + "\" width=\"" + to_string(catapulta->arm) + "\" height=\"20\" 	style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n"; // braccio
    cat += "<rect x=\"" + to_string(610 - catapulta->arm) + "\" y=\"" + to_string(425 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + "\" width=\"80\" height=\"35\" 	style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n"; // estremita braccio
    cat += "</g>\n";
    cat += "<rect x=\"500\" y=\"" + to_string(450 + catapulta->rad - catapulta->hbase - catapulta->hbox) + "\" width=\"200\" height=\"" + to_string(catapulta->hbox) + "\" style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n";// cassone
    cat += "<circle cx=\"350\" cy=\"450\" r=\"" + to_string(catapulta->rad) + "\" stroke=\"black\" stroke-width=\"9\" fill=\"#a5532a\" />\n\n"; // ruota sx
    cat += "<circle cx=\"650\" cy=\"450\" r=\"" + to_string(catapulta->rad) + "\" stroke=\"black\" stroke-width=\"9\" fill=\"#a5532a\" />\n"; // ruota dx
    cat += "<circle cx=\"600\" cy=\"" + to_string(450 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + "\" r=\"3\" stroke=\"black\" stroke-width=\"5\" fill=\"white\" />\n"; // perno del braccio

    //macchina
    cat += "<g transform=\"rotate(" + to_string( 90 - catapulta->alfa) + ",600," + to_string(450 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + ") translate(" + to_string(550 - catapulta->arm) + "," + to_string(330 + catapulta->rad - catapulta->hbase - (catapulta->hbox/2)) + ") scale(0.25)\">\n";
    cat += svg;
    */
    /*cat += "<rect x='225.000000' y='260.000000' rx='10' ry='10' width='350.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>\n";
	cat += "<circle cx='295.000000' cy='340.000000' r='40.000000' stroke='black' stroke-width='3' fill='black'/>\n";
	cat += "<circle cx='295.000000' cy='340.000000' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>\n";
	cat += "<circle cx='505.000000' cy='340.000000' r='40.000000' stroke='black' stroke-width='3' fill='black'/>\n";
	cat += "<circle cx='505.000000' cy='340.000000' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>\n";
	cat += "<polygon points='285.000336,260.000000 325.000000,199.999847 425.000000,199.999847 425.000000,260.000000 285.000336,260.000000' style='fill:red;stroke:black;stroke-width:5'/>\n";
	cat += "<polygon points='425.000000,199.999847 505.000000,260.000000 425.000000,260.000000' style='fill:lightblue;stroke:black;stroke-width:5' />\n";
	cat += "<rect x='235.000000' y='230.000000' width='20.000000' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>\n";
    cat += "</a>\n";
    cat += "</svg>\n";*/
  //  return cat;
//}


void mg_file_w(string cat){

    if(cat == "") {
        cout << "The file is empty or you haven't selected/created a file yet" << endl;
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
    string nuovastringa, newstring,filer;

    cout << "Type file name (es: catcatapult.svg)" << endl;
    cin >> filer;
    // Read from the text file
    ifstream MyReadFile(filer);
    
    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, newstring)) {
        
        nuovastringa += newstring;

        
        // Output the text from the file
        cout << newstring;
    }
    return nuovastringa;
}

void mg_destroy(){
    int status;
    char fileName[20];
    cout << "Enter the Name of File you want to delete: ";
    cin >> fileName;
    status = remove(fileName);
    if(status==0)
        cout<<"\nFile Deleted Successfully!";
    else
        cout<<"\nErorr Occurred!";
    cout<<endl;
}

void mg_init_cat(mgCatapult* catapulta){
    
        cout << "define wheel radius ( 20 - 100 ): ";
        cin >>  catapulta -> rad ;
        cout << "define bed hight ( wheel radius - wheel diameter): ";
        cin >> catapulta -> hbase;
        cout << "define box hight ( 0 - 100 ): ";
        cin >> catapulta -> hbox;
        cout << "define arm length: ( 100 - 500 ) ";
        cin >> catapulta -> arm;
        cout << "define launch angle ( > 0 ): ";
        cin >> catapulta -> alfa;

        if ( mg_check(catapulta) ){
            cout << "The set values are correct, a .svg file can be created" << endl;
            mg_catSVG(catapulta);
            return;
        }
    
}

void mg_parce_cat(string cat, mgCatapult* catapulta){
    catapulta->rad = mg_find_rad(cat,catapulta);
    catapulta->alfa = mg_find_alfa(cat,catapulta);
    catapulta->hbase = mg_find_hbase(cat,catapulta);
    catapulta->hbox = mg_find_hbox(cat,catapulta);
    catapulta->arm = mg_find_arm(cat,catapulta);
}

float mg_find_rad(string cat, mgCatapult* catapulta){
    float true_val;
    string valore,target;
    target = "<circle cx=\"350\" cy=\"450\" r=\"";
    size_t found_rad = cat.find(target) + target.size() ;
    if (found_rad != string::npos){
        valore = cat.substr(found_rad, 4);
        true_val = stof(valore);
        cout << "The wheel radius is " << true_val << endl;
    };
    return true_val;
}

float mg_find_alfa(string cat, mgCatapult* catapulta){
    float true_val;
    string valore,target;
    target = "<g transform=\"rotate(";
    size_t found_alfa = cat.find(target) + target.size() ;
    if (found_alfa != string::npos){
        valore = cat.substr(found_alfa, 8);
        true_val = 90 - stof(valore);
        cout << "The launch angle is " << true_val << endl;
    };
    return true_val;
}

float mg_find_hbase(string cat, mgCatapult* catapulta){
    float true_val;
    string valore,target;
    target = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">"; // intestazione
    target += "<rect x=\"0\" y=\"0\" width=\"800\" height=\"600\" style=\"fill:white;stroke:white;stroke-width:2\" />"; // sfondo bianco
    target += "<rect x=\"250\" y=\"";
    size_t found_hbase = target.size() ; //evito di utilizzare cat.find(target) perchè essendo il primo valore di interesse,
                                        // avrà sempre la stessa posizione nella stringa 
    if (found_hbase != string::npos){
        valore = cat.substr(found_hbase, 7);
        true_val = 450 + catapulta->rad - stof(valore);
        cout << "The hight of the base is " << true_val << endl;
    };
    return true_val;
}

float mg_find_hbox(string cat, mgCatapult* catapulta){ //               -------------------------------------per terzo dopo rad e hbase
    string valore,target;
    float true_val;
    target = "<rect x=\"500\" y=\"";
    size_t found_hbox = cat.find(target) + target.size() ;
    if (found_hbox != string::npos){
        valore = cat.substr(found_hbox, 7);
        true_val = 450 + catapulta->rad - catapulta->hbase - stof(valore);
        cout << "The hight of the box is " << true_val << endl;
    };
    return true_val;
}

float mg_find_arm(string cat, mgCatapult* catapulta){
    string valore,target;
    float true_val;
    target = "style=\"fill:#a5532a;stroke:black;stroke-width:2\" />"; 
    target += "<rect x=\"";
    size_t found_arm = cat.find(target) + target.size() ;
    if (found_arm != string::npos){
        valore = cat.substr(found_arm, 7);
        true_val = 610 - stof(valore);
        cout << "The length of the arm is " << true_val << endl;
    };
    return true_val;
}
