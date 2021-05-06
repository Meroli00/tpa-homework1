using namespace std;

#include "mgCatapult.h"
#include <iostream>
#include <string>


int main(){
    
    int risp;
    mgCatapult* catapulta;
    string cat;

    cout << "Choose an option:" << endl;
    cout << "[1] Create a new catapult" << endl;
    cout << "[2] Save catapult as a svg file" << endl;
    cout << "[3] Load a catapult" << endl;
    cout << "[4] modify a previously created catapult" << endl;
    cout << "[5] print the current svg file text" << endl;
    cout << "[6] Exit the program" << endl;  

    cin >> risp;

    while(risp!=6){
        switch (risp)
        {
        case 1:
            mg_init_cat(catapulta);
            cat = mg_catSVG(catapulta);
            break;
        case 2:
            mg_file_w(cat);
            break;
        case 3:
            cat = mg_file_r();
            break;
        case 4:
            //lancia fun per modificare un file svg
            break;
        case 5:
            cout << "the current svg text is: " << endl;
            if (cat==""){
                cout << "the file is empty, or you havent selected/created a file yet";
            };
            cout << cat << endl;
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