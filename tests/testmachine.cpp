#include "../include/catch2/catch2.hpp"
#include "../include/mgMachine.h"

TEST_CASE("dovrebbe avere come output 0 perchè le due machine sono uguali","[mgMachine]"){
    mgMachine* machine1 = mg_newmachine();
    mgMachine* machine2 = mg_newmachine();
    
    machine1->car.cap.x1  = machine2->car.cap.x1 = 301.429 ;
    machine1->car.cap.x2  = machine2->car.cap.x2 = 335.714 ;
    machine1->car.cap.x3  = machine2->car.cap.x3 = 421.429 ;
    machine1->car.cap.x4  = machine2->car.cap.x4 = 421.429 ;
    machine1->car.cap.x5  = machine2->car.cap.x5 = 301.429 ;
    machine1->car.cap.y1  = machine2->car.cap.y1 = 250 ;
    machine1->car.cap.y2  = machine2->car.cap.y2 = 175 ;
    machine1->car.cap.y3  = machine2->car.cap.y3 = 175 ;
    machine1->car.cap.y4  = machine2->car.cap.y4 = 250 ;
    machine1->car.cap.y5  = machine2->car.cap.y5 = 250 ;
    machine1->car.car.cx = machine2->car.car.cx = 250 ;
    machine1->car.car.cy  = machine2->car.car.cy = 250 ;
    machine1->car.car.height  = machine2->car.car.height = 100 ;
    machine1->car.car.width  = machine2->car.car.width = 300 ;
    machine1->car.dx.centrox  = machine2->car.dx.centrox = 495 ;
    machine1->car.dx.centroy  = machine2->car.dx.centroy = 350 ;
    machine1->car.dx.cerchione  = machine2->car.dx.cerchione = 30.9375 ;
    machine1->car.dx.ruota  = machine2->car.dx.ruota = 305 ;

    machine1->car.fin.p1x  = machine2->car.fin.p1x = 421.429 ;
    machine1->car.fin.p2x  = machine2->car.fin.p2x = 490 ;
    machine1->car.fin.p3x  = machine2->car.fin.p3x = 421.429 ;
    machine1->car.fin.p1y  = machine2->car.fin.p1y = 175 ;
    machine1->car.fin.p2y  = machine2->car.fin.p2y = 250 ;
    machine1->car.fin.p3y  = machine2->car.fin.p3y = 250 ;   
    machine1->car.spoil.heights  = machine2->car.spoil.heights = 37.5 ;
    machine1->car.spoil.px  = machine2->car.spoil.px = 258.271 ;
    machine1->car.spoil.py  = machine2->car.spoil.py = 212 ;
    machine1->car.spoil.widths  = machine2->car.spoil.widths = 17.14 ;
    machine1->car.sx.centrox  = machine2->car.sx.centrox = 305 ;
    machine1->car.sx.centroy  = machine2->car.sx.centroy = 350 ;
    machine1->car.sx.cerchione  = machine2->car.sx.cerchione = 605 ;
    machine1->car.sx.ruota  = machine2->car.sx.ruota = 30.9375 ;
    machine1->catap.alfa  = machine2->catap.alfa = 80 ;
    machine1->catap.arm  = machine2->catap.arm = 450 ;
    machine1->catap.hbox  = machine2->catap.hbox = 70 ;
    machine1->catap.hbase  = machine2->catap.hbase = 60 ; 

    mg_are_equal(machine1, machine2);

    REQUIRE(mg_are_equal(machine1, machine2) == 0);

    delete(machine1);
    delete(machine2);
}


TEST_CASE("dovrebbe avere come output 1 perchè le due machine sono diverse","[mgMachine]"){
    mgMachine* machine1 = mg_newmachine();
    mgMachine* machine2 = mg_newmachine();

    // valori diversi
    machine1->car.cap.x1  = 300 ;          
    machine2->car.cap.x1 = 301.429 ;

    machine1->car.cap.x2  = machine2->car.cap.x2 = 335.714 ;
    machine1->car.cap.x3  = machine2->car.cap.x3 = 421.429 ;
    machine1->car.cap.x4  = machine2->car.cap.x4 = 421.429 ;
    machine1->car.cap.x5  = machine2->car.cap.x5 = 301.429 ;
    machine1->car.cap.y1  = machine2->car.cap.y1 = 250 ;
    machine1->car.cap.y2  = machine2->car.cap.y2 = 175 ;
    machine1->car.cap.y3  = machine2->car.cap.y3 = 175 ;
    machine1->car.cap.y4  = machine2->car.cap.y4 = 250 ;
    machine1->car.cap.y5  = machine2->car.cap.y5 = 250 ;
    machine1->car.car.cx = machine2->car.car.cx = 250 ;
    machine1->car.car.cy  = machine2->car.car.cy = 250 ;
    machine1->car.car.height  = machine2->car.car.height = 100 ;
    machine1->car.car.width  = machine2->car.car.width = 300 ;
    machine1->car.dx.centrox  = machine2->car.dx.centrox = 495 ;
    machine1->car.dx.centroy  = machine2->car.dx.centroy = 350 ;
    machine1->car.dx.cerchione  = machine2->car.dx.cerchione = 30.9375 ;
    machine1->car.dx.ruota  = machine2->car.dx.ruota = 305 ;
    machine1->car.fin.p1x  = machine2->car.fin.p1x = 421.429 ;
    machine1->car.fin.p2x  = machine2->car.fin.p2x = 490 ;
    machine1->car.fin.p3x  = machine2->car.fin.p3x = 421.429 ;
    machine1->car.fin.p1y  = machine2->car.fin.p1y = 175 ;
    machine1->car.fin.p2y  = machine2->car.fin.p2y = 250 ;
    machine1->car.fin.p3y  = machine2->car.fin.p3y = 250 ;   
    machine1->car.spoil.heights  = machine2->car.spoil.heights = 37.5 ;
    machine1->car.spoil.px  = machine2->car.spoil.px = 258.271 ;
    machine1->car.spoil.py  = machine2->car.spoil.py = 212 ;
    machine1->car.spoil.widths  = machine2->car.spoil.widths = 17.14 ;
    machine1->car.sx.centrox  = machine2->car.sx.centrox = 305 ;
    machine1->car.sx.centroy  = machine2->car.sx.centroy = 350 ;
    machine1->car.sx.cerchione  = machine2->car.sx.cerchione = 605 ;
    machine1->car.sx.ruota  = machine2->car.sx.ruota = 30.9375 ;
    machine1->catap.alfa  = machine2->catap.alfa = 80 ;
    machine1->catap.arm  = machine2->catap.arm = 450 ;
    machine1->catap.hbox  = machine2->catap.hbox = 70 ;
    machine1->catap.hbase  = machine2->catap.hbase = 60 ; 

    mg_are_equal(machine1, machine2);

    REQUIRE(mg_are_equal(machine1, machine2) == 1);

    delete(machine1);
    delete(machine2);
}


TEST_CASE("dovrebbe eliminare l'oggetto machine","[mgMachine]"){
    mgMachine* catcar = mg_newmachine();

    mg_destroyM(catcar);

    REQUIRE(catcar == NULL);
}