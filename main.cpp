using namespace std;

#include <mgCatapult.h>
#include <iostream>
#include <string>


int main(){
    
    int risp;
    mgCatapult* catapulta;


    cout << "Choose an option:" << endl;
    cout << "[1] Create a new catapult" << endl;
    cout << "[2] Save catapult as a svg file" << endl;
    cout << "[3] Delete a previously created catapult" << endl;
    cout << "[4] Load a catapult" << endl;
    cout << "[5] Exit the program" << endl;  

    cin >> risp;

    while(risp!=5){
        switch (risp)
        {
        case 1:
            //lancia fun per creare un svg
            break;
        case 2:
            //lancia fun salvare il file svg
            break;
        case 3:
            //lancia fun per eliminare un file svg
            break;
        case 4:
            //lancia fun per caricare un file svg
            break;
        case 5:
            cout << "Program ended" << endl;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }
return 0;
}