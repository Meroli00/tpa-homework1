#include "../include/mgCatapult.h"
#include "../include/Car.h"
#include <math.h>
#include <iostream>
#include <string>
#include <cstring>


#define _USE_MATH_DEFINES

using namespace std;

mgCatapult *mg_newcat()
{
    mgCatapult *new_cat = new mgCatapult;
    return new_cat;
}

void mg_start(mgCatapult* catapulta){
    double a,b,c,d,e;
    cout << "define wheel radius ( 20 - 100 ): ";
    cin >> a;
    mg_set_rad(catapulta,a);
    cout << "define bed hight ( wheel radius - wheel diameter): ";
    cin >> b;
    mg_set_hbase(catapulta,b);
    cout << "define box hight ( 0 - 100 ): ";
    cin >> c;
    mg_set_hbox(catapulta,c);
    cout << "define arm length: ( 100 - 500 ) ";
    cin >> d;
    mg_set_arm(catapulta,d);
    cout << "define launch angle ( > 0 ): ";
    cin >> e;
    mg_set_alfa(catapulta,e);

    mg_error_sig(catapulta);
}


void mg_set_rad(mgCatapult *catapulta, double a){
    catapulta->rad = a;
}
void mg_set_hbase(mgCatapult *catapulta, double b){
    catapulta->hbase = b;
}
void mg_set_hbox(mgCatapult *catapulta, double c){
    catapulta->hbox = c;
}
void mg_set_arm(mgCatapult *catapulta, double d){
    catapulta->arm = d;
}
void mg_set_alfa(mgCatapult *catapulta, double e){
    catapulta->alfa = e;
}


int mg_check_rad(mgCatapult *catapulta){
    if ((catapulta->rad < 20) || (catapulta->rad > 100)){
        return 1;
    } else {return 0;}
}
int mg_check_hbox(mgCatapult *catapulta){
    if (catapulta->hbox < 0 || catapulta->hbox > 100){
        return 1;
    } else {return 0;}
}
int mg_check_hbase(mgCatapult *catapulta){
    if (catapulta->hbase < catapulta->rad || catapulta->hbase > 2*catapulta->rad){
        return 1;
    } else {return 0;}
}
int mg_check_arm(mgCatapult *catapulta){
    if (catapulta->arm < 100 || catapulta->arm > 500){
        return 1;
    } else {return 0;}
}
int mg_check_alfa(mgCatapult *catapulta){
    float alfamax = 90 + atan2f(catapulta->hbox, 700) * 180 / 3.14;
    if ((catapulta->alfa < 0) || (catapulta->alfa > alfamax)){
        return 1;
    } else {return 0;}
}

int mg_tot_check(mgCatapult* catapulta){
if ( mg_check_rad(catapulta)==0 &&     
    mg_check_hbase(catapulta)==0 &&   
    mg_check_hbox(catapulta)==0 &&    
    mg_check_arm(catapulta)==0 &&        
    mg_check_alfa(catapulta)==0){return 0;}
    else {return 1; }
}

void mg_error_sig(mgCatapult* catapulta){

    while(mg_check_rad(catapulta) != 0){
        double newval;
        cout << "the radius must be between 20 and 100" << endl;
        cout << "choose a new value: ";
        cin >> newval;
        mg_set_rad(catapulta,newval);
    }

    while(mg_check_hbox(catapulta) != 0){
        double newval;
        cout << "the hight of the box must be between 0 and 100" << endl;
        cout << "choose a new value: ";
        cin >> newval;
        mg_set_hbox(catapulta,newval);
    }

    while(mg_check_hbase(catapulta) != 0){
        double newval;
        int k;
        double m;
        cout << "the hight of the base must be between " << catapulta->rad << " and " << 2*catapulta->rad << endl;
        cout << "choose a new value: ";
        cin >> m;
        mg_set_hbase(catapulta,m);
    }

    while(mg_check_arm(catapulta) != 0){
        double newval;
        cout << "the length of rhe arm must be between 100 and 500" << endl;
        cout << "choose a new value: ";
        cin >> newval;
        mg_set_arm(catapulta,newval);
    }

    while(mg_check_alfa(catapulta) != 0){
        double newval;
        float alfamax = 90 + atan2f(catapulta->hbox, 700) * 180 / 3.14;
        cout << "the angle of launch must be between 0 and " << alfamax << endl;
        cout << "choose a new value: ";
        cin >> newval;
        mg_set_alfa(catapulta,newval);
    }
}

string mg_catSVG(mgCatapult *catapulta, int with_measures)
{
    string cat;
    cat = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">\n\n";                                                                                                                                                                                        // intestazione
    cat += "<rect x=\"0\" y=\"0\" width=\"800\" height=\"600\" style=\"fill:white;stroke:white;stroke-width:2\" />\n";                                                                                                                                                          // sfondo bianco
    cat += "<rect x=\"250\" y=\"" + to_string(450 + catapulta->rad - catapulta->hbase) + "\" width=\"500\" height=\"20\" style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n\n";                                                                                            // base
    cat += "<g transform=\"rotate(" + to_string(90 - catapulta->alfa) + ",600," + to_string(450 + catapulta->rad - catapulta->hbase - (catapulta->hbox / 2)) + ")\">\n";                                                                                                        // sdr ruotato
    cat += "<rect x=\"" + to_string(610 - catapulta->arm) + "\" y=\"" + to_string(440 + catapulta->rad - catapulta->hbase - (catapulta->hbox / 2)) + "\" width=\"" + to_string(catapulta->arm) + "\" height=\"20\" 	style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n"; // braccio
    cat += "<rect x=\"" + to_string(610 - catapulta->arm) + "\" y=\"" + to_string(425 + catapulta->rad - catapulta->hbase - (catapulta->hbox / 2)) + "\" width=\"80\" height=\"35\" 	style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n";                                 // estremita braccio
    cat += "</g>\n";
    cat += "<rect x=\"500\" y=\"" + to_string(450 + catapulta->rad - catapulta->hbase - catapulta->hbox) + "\" width=\"200\" height=\"" + to_string(catapulta->hbox) + "\" style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n"; // cassone
    cat += "<circle cx=\"350\" cy=\"450\" r=\"" + to_string(catapulta->rad) + "\" stroke=\"black\" stroke-width=\"9\" fill=\"#a5532a\" />\n\n";                                                                                      // ruota sx
    cat += "<circle cx=\"650\" cy=\"450\" r=\"" + to_string(catapulta->rad) + "\" stroke=\"black\" stroke-width=\"9\" fill=\"#a5532a\" />\n";                                                                                        // ruota dx
    cat += "<circle cx=\"600\" cy=\"" + to_string(450 + catapulta->rad - catapulta->hbase - (catapulta->hbox / 2)) + "\" r=\"3\" stroke=\"black\" stroke-width=\"5\" fill=\"white\" />\n";                                           // perno del braccio
    cat += "</svg>\n";

    if (with_measures == 2)
    {
        //quotature
        cat += "<g transform=\"rotate(" + to_string(90 - catapulta->alfa) + ",600," + to_string(450 + catapulta->rad - catapulta->hbase - (catapulta->hbox / 2)) + ")\">\n";
        cat += "<line x1=\"" + to_string(610 - catapulta->arm) + "\" y1=\"" + to_string(410 + catapulta->rad - catapulta->hbase - (catapulta->hbox / 2)) + "\" x2=\"610\" y2=\"" + to_string(410 + catapulta->rad - catapulta->hbase - (catapulta->hbox / 2)) + "\" style=\"stroke:rgb(0,0,0);stroke-width:1\" />\n";
        cat += "<text x=\"" + to_string(570 - catapulta->arm / 2) + "\" y=\"" + to_string(400 + catapulta->rad - catapulta->hbase - (catapulta->hbox / 2)) + "\" fill=\"black\">" + to_string(catapulta->arm) + " cm" + "</text>\n";
        cat += "</g>\n";
        cat += "<text x=\"630\" y=\"" + to_string(400 + catapulta->rad - catapulta->hbase - (catapulta->hbox / 2)) + "\" fill=\"black\">" + to_string(catapulta->alfa) + " gradi" + "</text>\n";
        cat += "<line x1=\"200\" y1=\"" + to_string(450 + catapulta->rad - catapulta->hbase) + "\" x2=\"200\" y2=\"" + to_string(450 + catapulta->rad) + "\" style=\"stroke:rgb(0,0,0);stroke-width:1\" />\n";
        cat += "<text x=\"100\" y=\"" + to_string(450 + catapulta->rad - catapulta->hbase / 2) + "\" fill=\"black\">" + to_string(catapulta->hbase) + " cm" + "</text>\n";
        cat += "<line x1=\"180\" y1=\"" + to_string(450 + catapulta->rad - catapulta->hbase - (catapulta->hbox)) + "\" x2=\"180\" y2=\"" + to_string(450 + catapulta->rad - catapulta->hbase) + "\" style=\"stroke:rgb(0,0,0);stroke-width:1\" />\n";
        cat += "<text x=\"80\" y=\"" + to_string(450 + catapulta->rad - catapulta->hbase - catapulta->hbox / 2) + "\" fill=\"black\">" + to_string(catapulta->hbox) + " cm" + "</text>\n";
        cat += "</svg>\n";
    }

    return cat;
}

void mg_file_w(string cat)
{

    if (cat == "")
    {
        cout << "The file is empty or you haven't selected/created a file yet" << endl;
    }
    if (cat != "")
    {
        string filew;

        cout << "Type file name (es: catcatapult.svg)" << endl;
        cin >> filew;

        // Create and open a text file
        ofstream MyFile("../svg/" + filew);

        // Write to the file
        MyFile << cat;

        // Close the file
        MyFile.close();
    }
}

string mg_file_r()
{
    string newstring, nuovastringa;
    int status;
    char target[95];
    char directory[100] = "../svg/";
    cout << "Type file name (es: catcatapult.svg)" << endl;
    cin >> target;
    strcat(directory, target);
    FILE *file;
    if (file = fopen(directory, "r"))
    {
        // Read from the text file
        ifstream MyReadFile(directory);

        // Use a while loop together with the getline() function to read the file line by line
        while (getline(MyReadFile, newstring))
        {

            nuovastringa += newstring;

            // Output the text from the file
            cout << newstring;
        }
        fclose(file);
    }
    else
    {
        cout << endl
             << "file doesn't exist" << endl
             << endl;
        nuovastringa = "";
    }

    return nuovastringa;
}

void mg_file_delete()
{
    int status;
    char target[95];
    char directory[100] = "../svg/";
    cout << "Enter the Name of File you want to delete: ";
    cin >> target;
    strcat(directory, target);
    status = remove(directory);
    if (status == 0)
        cout << "\nFile Deleted Successfully!";
    else
        cout << "\nFile doesn't exist";
    cout << endl;
}

void mg_parse_cat(string cat, mgCatapult *catapulta)
{
    if (cat != "")
    {
        catapulta->rad = mg_find_rad(cat, catapulta);
        catapulta->alfa = mg_find_alfa(cat, catapulta);
        catapulta->hbase = mg_find_hbase(cat, catapulta);
        catapulta->hbox = mg_find_hbox(cat, catapulta);
        catapulta->arm = mg_find_arm(cat, catapulta);
    }
}

float mg_find_rad(string cat, mgCatapult *catapulta)
{
    float true_val;
    string valore, target;
    target = "<circle cx=\"350\" cy=\"450\" r=\"";
    size_t found_rad = cat.find(target) + target.size();
    if (found_rad != string::npos)
    {
        valore = cat.substr(found_rad, 4);
        true_val = stof(valore);
        cout << "The wheel radius is " << true_val << endl;
    };
    return true_val;
}

float mg_find_alfa(string cat, mgCatapult *catapulta)
{
    float true_val;
    string valore, target;
    target = "<g transform=\"rotate(";
    size_t found_alfa = cat.find(target) + target.size();
    if (found_alfa != string::npos)
    {
        valore = cat.substr(found_alfa, 8);
        true_val = 90 - stof(valore);
        cout << "The launch angle is " << true_val << endl;
    };
    return true_val;
}

float mg_find_hbase(string cat, mgCatapult *catapulta)
{
    float true_val;
    string valore, target;
    target = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">";                                 // intestazione
    target += "<rect x=\"0\" y=\"0\" width=\"800\" height=\"600\" style=\"fill:white;stroke:white;stroke-width:2\" />"; // sfondo bianco
    target += "<rect x=\"250\" y=\"";
    size_t found_hbase = target.size(); //evito di utilizzare cat.find(target) perchè essendo il primo valore di interesse,
                                        // avrà sempre la stessa posizione nella stringa
    if (found_hbase != string::npos)
    {
        valore = cat.substr(found_hbase, 7);
        true_val = 450 + catapulta->rad - stof(valore);
        cout << "The hight of the base is " << true_val << endl;
    };
    return true_val;
}

float mg_find_hbox(string cat, mgCatapult *catapulta)
{
    string valore, target;
    float true_val;
    target = "<rect x=\"500\" y=\"";
    size_t found_hbox = cat.find(target) + target.size();
    if (found_hbox != string::npos)
    {
        valore = cat.substr(found_hbox, 7);
        true_val = 450 + catapulta->rad - catapulta->hbase - stof(valore);
        cout << "The hight of the box is " << true_val << endl;
    };
    return true_val;
}

float mg_find_arm(string cat, mgCatapult *catapulta)
{
    string valore, target;
    float true_val;
    target = "style=\"fill:#a5532a;stroke:black;stroke-width:2\" />";
    target += "<rect x=\"";
    size_t found_arm = cat.find(target) + target.size();
    if (found_arm != string::npos)
    {
        valore = cat.substr(found_arm, 7);
        true_val = 610 - stof(valore);
        cout << "The length of the arm is " << true_val << endl;
    };
    return true_val;
}

void mg_destroy(mgCatapult *catapulta)
{

    if (catapulta == NULL)
        return;

    delete catapulta;

    cout << "catapult correctly deleted" << endl;
}
