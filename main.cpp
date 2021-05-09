#include "mgCatapult.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int risp;
    string cat;
    mgCatapult* catapulta;
    mgCatapult device;
    catapulta = &device;

   while(risp!=6){
    cout << "Choose an option:" << endl;
    cout << "[1] Create a new catapult" << endl;
    cout << "[2] Save catapult as a svg file" << endl;
    cout << "[3] Load a catapult" << endl;
    cout << "[4] modify a previously created catapult" << endl;
    cout << "[5] print the current svg file text" << endl;
    cout << "[6] Exit the program" << endl;  

    cin >> risp;
        switch (risp)
        {
        case 1:
            int m;
            mg_init_cat(catapulta);
             while( m!=1 && m!=2 ){
                cout << "Select an option:" << endl;
                cout << "[1] svg without mesures" << endl;
                cout << "[2] svg with mesures" << endl;
                cin >> m ;
                if (m == 1){
                    cat = mg_catSVG(catapulta);
                };
                if (m == 2){
                    cat = mg_catSVG_quotato(catapulta);
                }
            }
            break;
        case 2:
            mg_file_w(cat);
            break;
        case 3:
            cat = mg_file_r();
            break;
        case 4:
            int r;
            mg_parce_cat(cat,catapulta);
            cout << "Do you wont to modify any value?" << endl;
            while( r!=1 && r!=2 ){
                cout << "[1] Yes , [2] No" << endl;
                cin >> r ;
                if (r == 1){
                    mg_init_cat(catapulta);
                };
            }
            break;
        case 5:
            cout << "the current svg text is: " << endl;
            if (cat==""){
                cout << "the file is empty, or you havent selected/created a file yet";
            };
            cout << cat;
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