#include "C:\Users\giaco\Desktop\compito 1\include\mgCatapult.h"
#include "C:\Users\giaco\Desktop\compito 1\include\Car.h"
#include "C:\Users\giaco\Desktop\compito 1\src\mgMachine.cpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int risp;
    string cat = "";
    mgCatapult* catapulta;
    mgCatapult device;
    catapulta = &device;

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

   while(risp!=6){
    cout << "Choose an option:" << endl;
    cout << "[1] Create a new machine" << endl;
    cout << "[2] Save device as a svg file" << endl;
    cout << "[3] Load a file" << endl;
    cout << "[4] delete a file" << endl;
    cout << "[5] print the current svg file text" << endl;
    cout << "[6] Exit the program" << endl;  

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
                    cat = mg_deviceSVG(lanciamacc);
                };
                if (n == 2){
                    cout << "Car initialization" << endl;
                    macch = coca_cin_device(macch, pscelta, pdiametro, px, check);
                    macch = coca_try_device(macch, scelta, diametro, x);
                    lanciamacc->car = *macch;
                    cout << "Choose a catapult" << endl;
                    cat = mg_file_r();
                    mg_parce_cat(cat,catapulta);
                    lanciamacc->catap = *catapulta;
                    cat = mg_deviceSVG(lanciamacc);
                }
            }
            n=0;
            break;
        case 2:
            mg_file_w(cat);
            break;
        case 3:
            cat = mg_file_r();
            break;
        case 4:
            mg_destroy();
            break;
        case 5:
            cout << "the current svg text is: " << endl;
            if (cat==""){
                cout << "the file is empty, or you haven't selected/created a file yet" << endl;
            };
            cout << cat;
            break;
        case 6:
            cout << "Program ended" << endl;
            break;
            
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }
return 0;
}