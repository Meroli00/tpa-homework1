#ifndef MGCATAPULT_H
#define MGCATAPULT_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
 
struct mgCatapult
{
    float arm;
    float alfa;
    float hbox;
    float hbase;
    float rad;

    //mgCatapult(/*float _arm, float _alfa, float _hbox, float _hbase, float _rad*/){
    /*    arm = 0;
        alfa = 0;
        hbox = 0;
        hbase = 0;
        rad = 0;
    }

    void print()const{
        fprintf(stdout,"Braccio: %d\nAlfa: %d\nAlt. cassone: %d\n, Alt. base: %d\nRaggio: %d",arm, alfa,hbox,hbase,rad);
    }*/
};
void mg_parce_cat(string cat, mgCatapult* catapulta);
float mg_find_rad(string cat, mgCatapult* Ncatapulta);
float mg_find_alfa(string cat, mgCatapult* Ncatapulta);
float mg_find_hbase(string cat, mgCatapult* Ncatapulta);
float mg_find_hbox(string cat, mgCatapult* Ncatapulta);
float mg_find_arm(string cat, mgCatapult* Ncatapulta);
void mg_set_rad(mgCatapult* catapulta);     //
void mg_set_hbase(mgCatapult* catapulta);   //
void mg_set_hbox(mgCatapult* catapulta);    //  fun che permettono di modificare le dimensioni di un pezzo
void mg_set_arm(mgCatapult* catapulta);     //   
void mg_set_alfa(mgCatapult* catapulta);    //  
void mg_file_w(std::string cat);  // scrive su file la stringa che costituisce l'svg
std::string mg_file_r();    // legge da file una stringa 
std::string mg_catSVG_quotato(mgCatapult*catapulta);
std::string mg_catSVG(mgCatapult* catapulta);    // costruisce la stringa
int mg_check(mgCatapult* catapulta);    // controlla i vincoli
void mg_init_cat(mgCatapult* catapulta);    // crea una nuova catapulta inizializzando nuove variabili


#endif
