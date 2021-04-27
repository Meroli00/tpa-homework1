#ifndef MGCATAPULT_H
#define MGCATAPULT_H

#include <iostream>
#include <string>

struct mgCatapult
{
    float arm;
    float alfa;
    float hbox;
    float hbase;
    float rad;

    mgCatapult(/*float _arm, float _alfa, float _hbox, float _hbase, float _rad*/){
        arm = 0;
        alfa = 0;
        hbox = 0;
        hbase = 0;
        rad = 0;
    }

    void print()const{
        fprintf(stdout,"Braccio: %d\nAlfa: %d\nAlt. cassone: %d\n, Alt. base: %d\nRaggio: %d",arm, alfa,hbox,hbase,rad);
    }
        
};
void mg_filew(string cat);  //scrive su file il file la stringa che costituisce l'svg
std::string mg_catSVG(mgCatapult* catapulta);    //costruisce la stringa
int mg_check(mgCatapult* catapulta);    //controlla i vincoli
void mg_init_cat(mgCatapult* catapulta);    //crea una nuova catapulta inizializzando nuove variabili


#endif
