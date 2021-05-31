#include "../include/mgCatapult.h"
#include "../include/Car.h"
#include "../include/mgMachine.h"
#include <math.h>
#include <iostream>
#include <string>

#define _USE_MATH_DEFINES

using namespace std;

mgMachine* mg_newmachine(){
    mgMachine * new_machine = new mgMachine;
    return new_machine;
}

string mg_machineSVG(mgMachine* catcar){
    string cat;
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
    cat += "</g>\n";
    cat += "</svg>\n";
    return cat;
}


bool mg_are_equal(mgMachine* machine1, mgMachine* machine2){
    string cat1, cat2;
    cat1 = mg_file_r();
    while (cat1 == ""){
        cout << "Try again" << endl << endl;
        cout << "First machine:" << endl;
        cat1 = mg_file_r();
    }
    mg_parse_cat(cat1, &machine1->catap);
    coca_parse_deviceV2(cat1, &machine1->car);
    
    cat2 = mg_file_r();
    while (cat1 == ""){
        cout << "Try again" << endl << endl;
        cout << "Second machine:" << endl;
        cat2 = mg_file_r();
    }
    mg_parse_cat(cat2, &machine2->catap);
    coca_parse_deviceV2(cat2, &machine2->car);

    cout << endl << "TESTTTTTTTTTTTTTTTTTTTT" << endl << endl;
    cout << machine1->car.cap.x1 << "  ALTRO:  " << machine2->car.cap.x1 << endl;
    cout <<  machine1->car.cap.x2 << "  ALTRO:  "  << machine2->car.cap.x2 << endl;
    cout <<   machine1->car.cap.x3 << "  ALTRO:  "  << machine2->car.cap.x3 << endl;  
    cout <<   machine1->car.cap.x4 << "  ALTRO:  "  << machine2->car.cap.x4 << endl;   
    cout <<   machine1->car.cap.x5 << "  ALTRO:  "  << machine2->car.cap.x5 << endl;   
    cout <<   machine1->car.cap.y1 << "  ALTRO:  "  << machine2->car.cap.y1 << endl;   
    cout <<   machine1->car.cap.y2 << "  ALTRO:  "  << machine2->car.cap.y2 << endl;   
    cout <<   machine1->car.cap.y3 << "  ALTRO:  "  << machine2->car.cap.y3 << endl;   
    cout <<   machine1->car.cap.y4 << "  ALTRO:  "  << machine2->car.cap.y4 << endl;   
    cout <<   machine1->car.cap.y5 << "  ALTRO:  "  << machine2->car.cap.y5 << endl;  
    
    cout << machine1->car.car.cx << "  ALTRO:  "  << machine2->car.car.cx << endl;  
        cout <<  machine1->car.car.cy <<  "  ALTRO:  " <<   machine2->car.car.cy<< endl;   
        cout <<  machine1->car.car.height <<  "  ALTRO:  " <<   machine2->car.car.height<< endl;   
        cout <<  machine1->car.car.width <<  "  ALTRO:  " <<   machine2->car.car.width << endl;

        cout <<  machine1->car.dx.centrox <<  "  ALTRO:  " <<   machine2->car.dx.centrox << endl;   
        cout <<  machine1->car.dx.centroy <<  "  ALTRO:  " <<   machine2->car.dx.centroy << endl;  
        cout <<  machine1->car.dx.cerchione <<  "  ALTRO:  " <<   machine2->car.dx.cerchione << endl;   
        //cout <<  machine1->car.dx.ruota <<  "  ALTRO:  " <<   machine2->car.dx.ruota << endl;

        cout <<  machine1->car.fin.p1x <<  "  ALTRO:  " <<   machine2->car.fin.p1x << endl;
        cout <<  machine1->car.fin.p2x <<  "  ALTRO:  " <<   machine2->car.fin.p2x << endl;  
        cout <<  machine1->car.fin.p3x <<  "  ALTRO:  " <<   machine2->car.fin.p3x << endl;  
        cout <<  machine1->car.fin.p1y <<  "  ALTRO:  " <<   machine2->car.fin.p1y << endl;   
        cout <<  machine1->car.fin.p2y <<  "  ALTRO:  " <<   machine2->car.fin.p2y << endl;   
        cout <<  machine1->car.fin.p3y <<  "  ALTRO:  " <<   machine2->car.fin.p3y << endl;   
        
        cout <<  machine1->car.spoil.heights <<  "  ALTRO:  " <<   machine2->car.spoil.heights << endl;   
        cout <<  machine1->car.spoil.px <<  "  ALTRO:  " <<   machine2->car.spoil.px << endl;   
        cout <<  machine1->car.spoil.py <<  "  ALTRO:  " <<   machine2->car.spoil.py << endl;   
        cout <<  machine1->car.spoil.widths <<  "  ALTRO:  " <<   machine2->car.spoil.widths << endl;   
        
        cout <<  machine1->car.sx.centrox <<  "  ALTRO:  " <<   machine2->car.sx.centrox << endl;   
        cout <<  machine1->car.sx.centroy <<  "  ALTRO:  " <<   machine2->car.sx.centroy << endl;   
  
        cout <<  machine1->car.sx.ruota <<  "  ALTRO:  " <<   machine2->car.sx.ruota << endl;  
         
        cout <<  machine1->catap.alfa <<  "  ALTRO:  " <<   machine2->catap.alfa << endl;   
        cout <<  machine1->catap.arm <<  "  ALTRO:  " <<   machine2->catap.arm << endl;   
        cout <<  machine1->catap.hbox <<  "  ALTRO:  " <<   machine2->catap.hbox  << endl;  
        cout <<  machine1->catap.hbase <<  "  ALTRO:  " <<   machine2->catap.hbase << endl; 

    if (
        (machine1->car.cap.x1 == machine2->car.cap.x1)
        &&  (machine1->car.cap.x2 == machine2->car.cap.x2)  
        &&  (machine1->car.cap.x3 == machine2->car.cap.x3)  
        &&  (machine1->car.cap.x4 == machine2->car.cap.x4)   
        &&  (machine1->car.cap.x5 == machine2->car.cap.x5)   
        &&  (machine1->car.cap.y1 == machine2->car.cap.y1)   
        &&  (machine1->car.cap.y2 == machine2->car.cap.y2)   
        &&  (machine1->car.cap.y3 == machine2->car.cap.y3)   
        &&  (machine1->car.cap.y4 == machine2->car.cap.y4)   
        &&  (machine1->car.cap.y5 == machine2->car.cap.y5)   

        &&  (machine1->car.car.cx== machine2->car.car.cx)   
        &&  (machine1->car.car.cy == machine2->car.car.cy)   
        &&  (machine1->car.car.height == machine2->car.car.height)   
        &&  (machine1->car.car.width == machine2->car.car.width)

        &&  (machine1->car.dx.centrox == machine2->car.dx.centrox)   
        &&  (machine1->car.dx.centroy == machine2->car.dx.centroy)  
        &&  (machine1->car.dx.cerchione == machine2->car.dx.cerchione)   
        //&&  (machine1->car.dx.ruota == machine2->car.dx.ruota)

        &&  (machine1->car.fin.p1x == machine2->car.fin.p1x)
        &&  (machine1->car.fin.p2x == machine2->car.fin.p2x)  
        &&  (machine1->car.fin.p3x == machine2->car.fin.p3x)  
        &&  (machine1->car.fin.p1y == machine2->car.fin.p1y)   
        &&  (machine1->car.fin.p2y == machine2->car.fin.p2y)   
        &&  (machine1->car.fin.p3y == machine2->car.fin.p3y)   
        
        &&  (machine1->car.spoil.heights == machine2->car.spoil.heights)   
        &&  (machine1->car.spoil.px == machine2->car.spoil.px)   
        &&  (machine1->car.spoil.py == machine2->car.spoil.py)   
        &&  (machine1->car.spoil.widths == machine2->car.spoil.widths)   
        
        &&  (machine1->car.sx.centrox == machine2->car.sx.centrox)   
        &&  (machine1->car.sx.centroy == machine2->car.sx.centroy)   
        //&&  (machine1->car.sx.cerchione == machine2->car.sx.cerchione)   
        &&  (machine1->car.sx.ruota == machine2->car.sx.ruota)  
         
        &&  (machine1->catap.alfa == machine2->catap.alfa)   
        &&  (machine1->catap.arm == machine2->catap.arm)   
        &&  (machine1->catap.hbox == machine2->catap.hbox )  
        &&  (machine1->catap.hbase == machine2->catap.hbase) 
        ) {
            cout << "debug TRUE" << endl << endl;
            return 0;
    }
    else {
        return 1;
    }
}

void mg_destroyM(mgMachine* machine){
    
    if (machine == NULL) return;

    delete machine;

    cout << "machine correctly deleted" << endl; 

}
