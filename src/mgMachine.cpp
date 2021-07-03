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
    cout << "First machine:" << endl;
    cat1 = mg_file_r();
    while (cat1 == ""){
        cout << "Try again" << endl << endl;
        cout << "First machine:" << endl;
        cat1 = mg_file_r();
    }
    mg_parse_cat(cat1, &machine1->catap);
    coca_parse_deviceV2(cat1, &machine1->car);
    
    cout << "Second machine:" << endl;
    cat2 = mg_file_r();
    while (cat1 == ""){
        cout << "Try again" << endl << endl;
        cout << "Second machine:" << endl;
        cat2 = mg_file_r();
    }
    mg_parse_cat(cat2, &machine2->catap);
    coca_parse_deviceV2(cat2, &machine2->car);
    if ( mg_compare(machine1,machine2) == 0 ) {return 0;}
    else {return 1;}
}


int mg_compare(mgMachine* machine1, mgMachine* machine2){
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

        &&  (machine1->car.sx.ruota == machine2->car.sx.ruota)  
         
        &&  (machine1->catap.alfa == machine2->catap.alfa)   
        &&  (machine1->catap.arm == machine2->catap.arm)   
        &&  (machine1->catap.hbox == machine2->catap.hbox )  
        &&  (machine1->catap.hbase == machine2->catap.hbase) 
       ) {return 0;}
       else {return 1;}
}


void mg_destroyM(mgMachine *catcar)
{

    if (catcar == NULL)
        return;
        
    delete catcar;

    cout << "machine correctly deallocated" << endl;
}

string mg_machine_arraySVG(mgMachine** arr, int n, coca_device** car_arr, int k){
    string cat;
    
    cat = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" + to_string(800*n + 500*k) + "\" height=\"600\">\n\n"; // intestazione
    cat += "<rect x=\"0\" y=\"0\" width=\" " + to_string(800*n + 500*k) + " \" height=\"600\" style=\"fill:white;stroke:white;stroke-width:2\" />\n"; // sfondo bianco

    for( int i=0 ; i<n ; i++){
        //catapulta        
        cat += "<a transform=\"translate(" + to_string(700*i) + ",0)\">\n";
        if (i != n-1){
            cat += "<line x1=\" " + to_string(750) + " \" y1=\" " + to_string(450 + 10 + arr[i]->catap.rad - arr[i]->catap.hbase) + " \" x2=\" ";
            cat += "" + to_string(1050) + " \" y2=\" " + to_string(450 + 10 + arr[i+1]->catap.rad - arr[i+1]->catap.hbase) + " \" style=\"stroke:rgb(0,0,0);stroke-width:1\" />\n";
        }
        cat += "<rect x=\"250\" y=\"" + to_string(450 + arr[i]->catap.rad - arr[i]->catap.hbase) + "\" width=\"500\" height=\"20\" style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n\n"; // base
        cat += "<g transform=\"rotate(" + to_string( 90 - arr[i]->catap.alfa) + ",600," + to_string(450 + arr[i]->catap.rad - arr[i]->catap.hbase - (arr[i]->catap.hbox/2)) + ")\">\n"; // sdr ruotato
        cat += "<rect x=\"" + to_string(610 - arr[i]->catap.arm) + "\" y=\"" + to_string(440 + arr[i]->catap.rad - arr[i]->catap.hbase - (arr[i]->catap.hbox/2)) + "\" width=\"" + to_string(arr[i]->catap.arm) + "\" height=\"20\" 	style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n"; // braccio
        cat += "<rect x=\"" + to_string(610 - arr[i]->catap.arm) + "\" y=\"" + to_string(425 + arr[i]->catap.rad - arr[i]->catap.hbase - (arr[i]->catap.hbox/2)) + "\" width=\"80\" height=\"35\" 	style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n"; // estremita braccio
        cat += "</g>\n";
        cat += "<rect x=\"500\" y=\"" + to_string(450 + arr[i]->catap.rad - arr[i]->catap.hbase - arr[i]->catap.hbox) + "\" width=\"200\" height=\"" + to_string(arr[i]->catap.hbox) + "\" style=\"fill:#a5532a;stroke:black;stroke-width:2\" />\n";// cassone
        cat += "<circle cx=\"350\" cy=\"450\" r=\"" + to_string(arr[i]->catap.rad) + "\" stroke=\"black\" stroke-width=\"9\" fill=\"#a5532a\" />\n\n"; // ruota sx
        cat += "<circle cx=\"650\" cy=\"450\" r=\"" + to_string(arr[i]->catap.rad) + "\" stroke=\"black\" stroke-width=\"9\" fill=\"#a5532a\" />\n"; // ruota dx
        cat += "<circle cx=\"600\" cy=\"" + to_string(450 + arr[i]->catap.rad - arr[i]->catap.hbase - (arr[i]->catap.hbox/2)) + "\" r=\"3\" stroke=\"black\" stroke-width=\"5\" fill=\"white\" />\n"; // perno del braccio

        //macchina
        cat += "<g transform=\"rotate(" + to_string( 90 - arr[i]->catap.alfa) + ",600," + to_string(450 + arr[i]->catap.rad - arr[i]->catap.hbase - (arr[i]->catap.hbox/2)) + ") translate(" + to_string(550 - arr[i]->catap.arm) + "," + to_string(330 + arr[i]->catap.rad - arr[i]->catap.hbase - (arr[i]->catap.hbox/2)) + ") scale(0.25)\">\n";
        cat += coca_strg_device(&arr[i]->car, 1, 0);
        cat += "</g>\n";
        cat += "</a>\n";     
    }

    double pos = 800*n + 50;

    if (k != 0){
        cat += "<line x1=\" " + to_string(700*(n-1) + 750) + " \" y1=\" " + to_string(450 + 10 + arr[n-1]->catap.rad - arr[n-1]->catap.hbase) + " \" x2=\" ";
        cat += "" + to_string( pos + 200 ) + " \" y2=\" " + to_string( 460 - car_arr[0]->dx.ruota/8 - car_arr[0]->car.height/8 ) + " \" style=\"stroke:rgb(0,0,0);stroke-width:1\" />\n";
    }
    

    for( int i=0 ; i<k ; i++){      //ciclo per aggiungere le macchine che trainano
        cat += "<g transform=\" translate(" + to_string( pos ) + "," + to_string(420 - car_arr[i]->dimensioney/5) + ") scale(0.5)\">\n";
        pos += car_arr[i]->car.width + 50; // aggiorno posizione prossima macchina

        if ( i < k-1 ){
            cat += "<line x1=\" " + to_string( car_arr[i]->dimensionex/2) + " \" y1=\" " + to_string(450 - car_arr[i]->dimensioney/4) + " \" x2=\" \n";
            cat += "" + to_string(car_arr[i+1]->dimensionex + car_arr[i]->car.width + 50) + " \" y2=\" " + to_string(450 - car_arr[i+1]->dimensioney/4) + " \" style=\"stroke:rgb(0,0,0);stroke-width:1\" />\n";
        }
        cat += coca_strg_device(car_arr[i], 1, 0);
        cat += "</g>\n"; 
    }

    cat += "</svg>\n";

    return cat;
    
}
