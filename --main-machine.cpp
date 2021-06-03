#include "include\mgMachine.h"
#include "include\Car.h"
#include "include\mgCatapult.h"
#include <iostream>
#include <string>
#include <csignal>

using namespace std;

int main(){
    
    int risp;
    string cat = "";
    mgCatapult* catapulta;
    catapulta = mg_newcat();

    int menu, icheck = 0;
    string svg;
    coca_device* macch = coca_init();
    int scelta, diametro, x;
    int* pscelta = &scelta;
    int* pdiametro = &diametro;
    int* px = &x;
    int* check = &icheck;

    mgMachine* lanciamacc;
    mgMachine machine;
    lanciamacc = &machine;

    while(risp!=8){
    cout << "Choose an option:" << endl;
    cout << "[1] Create a new machine" << endl;
    cout << "[2] Save machine as a svg file" << endl;
    cout << "[3] Load a file" << endl;
    cout << "[4] delete a file" << endl;
    cout << "[5] print the current svg file text" << endl;
    cout << "[6] check if 2 machines are the same" << endl;
    cout << "[7] delete current string and restart" << endl;
    cout << "[8] Exit the program" << endl;  

    cin >> risp;
        switch (risp)
        {
        case 1:
            int n;
            while( n!=1 && n!=2 ){
                cout << "Select an option:" << endl;
                cout << "[1] create a catapult" << endl;
                cout << "[2] load a catapult" << endl;
                cin >> n ;
                if (n == 1){
                    cout << "Car initialization" << endl;
                    macch = coca_cin_device(macch, pscelta, pdiametro, px, check);
                    macch = coca_try_device(macch, scelta, diametro, x); 
                    lanciamacc->car = *macch;
                    cout << "Catapult initialization" << endl;
                    mg_init_cat(catapulta);
                    lanciamacc->catap = *catapulta;
                    cat = mg_machineSVG(lanciamacc);
                };
                if (n == 2){
                    cout << "Car initialization" << endl;
                    macch = coca_cin_device(macch, pscelta, pdiametro, px, check);
                    macch = coca_try_device(macch, scelta, diametro, x);
                    lanciamacc->car = *macch;
                    cout << "Choose a catapult" << endl;
                    cat = mg_file_r();
                    mg_parse_cat(cat,catapulta);
                    lanciamacc->catap = *catapulta;
                    cat = mg_machineSVG(lanciamacc);
                }
            }
            n=0;
            break;
        case 2:
            mg_file_w(cat);
            break;
        case 3:
            cat = mg_file_r();
            while (cat == ""){
                cout << "Try again" << endl << endl;
                cat = mg_file_r();
            }
            break;
        case 4:
            mg_file_delete();
            break;
        case 5:
            cout << "the current svg text is: " << endl;
            if (cat==""){
                cout << "the file is empty, or you haven't selected/created a file yet" << endl;
            };
            cout << cat;
            break;
        case 6:
            cout << "First machine:" << endl;
            mgMachine* machine1 = mg_newmachine();
            cout << "Second machine:" << endl;
            mgMachine* machine2 = mg_newmachine();
            if (mg_are_equal(machine1, machine2)==0) {cout << endl << "The 2 machines selected are identical" << endl;}
            else {cout << endl << "The 2 machines selected are different" << endl;}
            break;
        case 7:
            cat = "";
            break;
        case 8:
            mg_destroyM(lanciamacc);
            
            cat = "";
            cout << endl << "Program ended" << endl;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }
return 0;
}