#include "../include/mgCatapult.h"
#include "../include/Car.h"
#include "../include/mgMachine.h"
#include <math.h>
#include <iostream>
#include <string>

#define _USE_MATH_DEFINES

using namespace std;


string mg_deviceSVG(mgMachine* catcar){
    string cat;
    //coca_device* provv = &(catcar->car);
    //catapulta
    
    cat = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">\n\n"; // intestazione
    cat += "<rect x=\"0\" y=\"0\" width=\"800\" height=\"600\" style=\"fill:white;stroke:white;stroke-width:2\" />\n"; // sfondo bianco
    cat += "<rect x=\"250\" y=\"" + to_string(450 + catcar->catap.rad - catcar->catap.hbase) + "\" width=\"500\" height=\"20\" style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n\n"; // base
    cat += "<g transform=\"rotate(" + to_string( 90 - catcar->catap.alfa) + ",600," + to_string(450 + catcar->catap.rad - catcar->catap.hbase - (catcar->catap.hbox/2)) + ")\">\n"; // sdr ruotato
    cat += "<rect x=\"" + to_string(610 - catcar->catap.arm) + "\" y=\"" + to_string(440 + catcar->catap.rad - catcar->catap.hbase - (catcar->catap.hbox/2)) + "\" width=\"" + to_string(catcar->catap.arm) + "\" height=\"20\" 	style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n"; // braccio
    cat += "<rect x=\"" + to_string(610 - catcar->catap.arm) + "\" y=\"" + to_string(425 + catcar->catap.rad - catcar->catap.hbase - (catcar->catap.hbox/2)) + "\" width=\"80\" height=\"35\" 	style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n"; // estremita braccio
    cat += "</g>\n";
    cat += "<rect x=\"500\" y=\"" + to_string(450 + catcar->catap.rad - catcar->catap.hbase - catcar->catap.hbox) + "\" width=\"200\" height=\"" + to_string(catcar->catap.hbox) + "\" style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n";// cassone
    cat += "<circle cx=\"350\" cy=\"450\" r=\"" + to_string(catcar->catap.rad) + "\" stroke=\"black\" stroke-width=\"9\" fill=\"#a5532a\" />\n\n"; // ruota sx
    cat += "<circle cx=\"650\" cy=\"450\" r=\"" + to_string(catcar->catap.rad) + "\" stroke=\"black\" stroke-width=\"9\" fill=\"#a5532a\" />\n"; // ruota dx
    cat += "<circle cx=\"600\" cy=\"" + to_string(450 + catcar->catap.rad - catcar->catap.hbase - (catcar->catap.hbox/2)) + "\" r=\"3\" stroke=\"black\" stroke-width=\"5\" fill=\"white\" />\n"; // perno del braccio

    //macchina
    cat += "<g transform=\"rotate(" + to_string( 90 - catcar->catap.alfa) + ",600," + to_string(450 + catcar->catap.rad - catcar->catap.hbase - (catcar->catap.hbox/2)) + ") translate(" + to_string(550 - catcar->catap.arm) + "," + to_string(330 + catcar->catap.rad - catcar->catap.hbase - (catcar->catap.hbox/2)) + ") scale(0.25)\">\n";
    cat += coca_strg_device(&catcar->car, 1, 0);
    return cat;
}

