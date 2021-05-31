#include "include/mgCatapult.h"
#include "include/Car.h"
#include <iostream>
#include <string>
#include <signal.h>

using namespace std;

int main(){
    
    int risp;
    string cat = "";
    mgCatapult* catapulta = mg_newcat();

    while(risp!=8){
    cout << endl;
    cout << "Choose an option:" << endl;
    cout << "[1] Create a new catapult" << endl;
    cout << "[2] Save catapult as a svg file" << endl;
    cout << "[3] Load a catapult" << endl;
    cout << "[4] modify a previously created catapult" << endl;
    cout << "[5] print the current svg file text" << endl;
    cout << "[6] delete a file" << endl;
    cout << "[7] delete current string" << endl;
    cout << "[8] Exit the program" << endl;  

    cin >> risp;
        switch (risp)
        {
        case 1:
            int with_measures;
            mg_init_cat(catapulta);
             while( with_measures!=1 && with_measures!=2 ){
                cout << "Select an option:" << endl;
                cout << "[1] svg without mesures" << endl;
                cout << "[2] svg with mesures" << endl;
                cin >> with_measures ;
            }
            cat = mg_catSVG(catapulta, with_measures);
            
            break;
        case 2:
            mg_file_w(cat);
            break;
        case 3:
            cat = mg_file_r();
            break;
        case 4:
            int r;
            if (cat==""){
                cout << "the file is empty, or you haven't selected/created a file yet" << endl;
            }
            else {
                mg_parse_cat(cat,catapulta);
                cout << "Do you wont to modify any value?" << endl;
                while( r!=1 && r!=2 ){
                    cout << "[1] Yes , [2] No" << endl;
                    cin >> r ;
                    if (r == 1){
                     mg_init_cat(catapulta);
                    }
                }
            r=0;
            }
            break;
        case 5:
            cout << "the current svg text is: " << endl;
            if (cat==""){
                cout << "the file is empty, or you haven't selected/created a file yet" << endl;
            };
            cout << cat;
            break;
        case 6:
            mg_file_delete();
            break;
        case 7:
            cat = "";
            break;
        case 8:
            mg_destroy(catapulta);
            cat = "";
            cout << "Program ended" << endl;
            break;
            
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }
return 0;
}