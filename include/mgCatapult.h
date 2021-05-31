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
};

void mg_parse_cat(string cat, mgCatapult* catapulta);   // recreates the entire struct from a svg file
float mg_find_rad(string cat, mgCatapult* Ncatapulta); // fun che trova il campo cat dello struct mgCatapult in un file di testo
float mg_find_alfa(string cat, mgCatapult* Ncatapulta); // fun che trova il campo alfa dello struct mgCatapult in un file di testo
float mg_find_hbase(string cat, mgCatapult* Ncatapulta); // fun che trova il campo hbase dello struct mgCatapult in un file di testo
float mg_find_hbox(string cat, mgCatapult* Ncatapulta); // fun che trova il campo hbox dello struct mgCatapult in un file di testo
float mg_find_arm(string cat, mgCatapult* Ncatapulta); // fun che trova il campo arm dello struct mgCatapult in un file di testo
void mg_set_rad(mgCatapult* catapulta);     //
void mg_set_hbase(mgCatapult* catapulta);   //
void mg_set_hbox(mgCatapult* catapulta);    //  fun che permettono di modificare le dimensioni di un pezzo
void mg_set_arm(mgCatapult* catapulta);     //   
void mg_set_alfa(mgCatapult* catapulta);    //  
void mg_file_w(std::string cat);  // scrive su file la stringa che costituisce l'svg
std::string mg_file_r();    // legge da file una stringa 
void mg_file_delete(); // deletes a file
std::string mg_catSVG(mgCatapult* catapulta, int m);    // costruisce la stringa
int mg_check(mgCatapult* catapulta);    // controlla i vincoli
void mg_init_cat(mgCatapult* catapulta);    // inizializza i valori dell'oggetto mgCatapult chiedendoli all'utente
void mg_destroy(mgCatapult* catapulta);     // funzione che cancella lo struct 
mgCatapult* mg_newcat();      // crea un nuovo oggetto di tipo mgCatapult
#endif
