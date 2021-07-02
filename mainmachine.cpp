#include "include/mgMachine.h"
#include "include/Car.h"
#include "include/mgCatapult.h"
#include <iostream>
#include <string>
#include <csignal>

using namespace std;

int main()
{

    int risp;
    string cat = "";
    mgCatapult *catapulta = mg_newcat();
    

    int menu, icheck = 0;
    string svg;
    coca_device *macch = coca_init();
    int scelta, diametro, x;
    int *pscelta = &scelta;
    int *pdiametro = &diametro;
    int *px = &x;
    int *check = &icheck;

    mgMachine *lanciamacc = mg_newmachine();

    while (risp != 9)
    {
        cout << "Choose an option:" << endl;
        cout << "[1] Create a new machine" << endl;
        cout << "[2] Save machine as a svg file" << endl;
        cout << "[3] Create a line of X catapults towed by Y cars" << endl;
        cout << "[4] Load a file" << endl;
        cout << "[5] delete a file" << endl;
        cout << "[6] print the current svg file text" << endl;
        cout << "[7] check if 2 machines are the same" << endl;
        cout << "[8] delete current string and restart" << endl;
        cout << "[9] Exit the program" << endl;

        cin >> risp;
        switch (risp)
        {
        case 1:
        {
            int n;
            while (n != 1 && n != 2)
            {
                cout << "Select an option:" << endl;
                cout << "[1] create a catapult" << endl;
                cout << "[2] load a catapult" << endl;
                cin >> n;
                if (n == 1)
                {
                    cout << "Car initialization" << endl;
                    macch = coca_cin_device(macch, pscelta, pdiametro, px, check);
                    macch = coca_try_device(macch, scelta, diametro, x);
                    lanciamacc->car = *macch;
                    cout << "Catapult initialization" << endl;
                    mg_start(catapulta);
                    lanciamacc->catap = *catapulta;
                    cat = mg_machineSVG(lanciamacc);
                };
                if (n == 2)
                {
                    cout << "Car initialization" << endl;
                    macch = coca_cin_device(macch, pscelta, pdiametro, px, check);
                    macch = coca_try_device(macch, scelta, diametro, x);
                    lanciamacc->car = *macch;
                    cout << "Choose a catapult" << endl;
                    cat = mg_file_r();
                    mg_parse_cat(cat, catapulta);
                    lanciamacc->catap = *catapulta;
                    cat = mg_machineSVG(lanciamacc);
                }
            }
            n = 0;
            break;
        }
        case 2:
        {
            mg_file_w(cat);
            break;
        }
        case 3:
        {
            int n = 0;
            while( n<=0 ){
                cout << "How many catapults do you want in your army?" << endl;
                cin >> n;
            }
            mgMachine** arr;
    
            arr = new mgMachine* [n];
            
            for( int i=0 ; i<n ; i++){
                mgCatapult *catapulta = mg_newcat();
                coca_device *macch = coca_init();
                mgMachine *lanciamacc = mg_newmachine();
                cout << "Car initialization" << endl;
                macch = coca_cin_device(macch, pscelta, pdiametro, px, check);
                macch = coca_try_device(macch, scelta, diametro, x);
                lanciamacc->car = *macch;
                cout << "Catapult initialization" << endl;
                mg_start(catapulta);
                lanciamacc->catap = *catapulta;
                cout << endl;

                arr[i] = lanciamacc;
            }

            int k = 0;
            while( k<=0 ){
                cout << "How many cars do you want to tawe your catapults?" << endl;
                cin >> k;
            }
            coca_device** car_arr;
    
            car_arr = new coca_device* [k];
            
            for( int i=0 ; i<k ; i++){
                coca_device *macch = coca_init();
                cout << "Car initialization" << endl;
                macch = coca_cin_device(macch, pscelta, pdiametro, px, check);
                macch = coca_try_device(macch, scelta, diametro, x);

                cout << endl;

                car_arr[i] = macch;
            }

            cat = mg_machine_arraySVG(arr,n,car_arr,k);

            for ( int i=0 ; i<n ; i++){
                delete arr[i];
            }
            delete[] arr;
            for ( int i=0 ; i<k ; i++){
                delete car_arr[i];
            }
            delete[] car_arr;
            
            break;
        }
        case 4:
        {
            cat = mg_file_r();
            while (cat == "")
            {
                cout << "Try again" << endl
                     << endl;
                cat = mg_file_r();
            }
            break;
        }
        case 5:
        {
            mg_file_delete();
            break;
        }
        case 6:
        {
            cout << "the current svg text is: " << endl;
            if (cat == "")
            {
                cout << "the file is empty, or you haven't selected/created a file yet" << endl;
            };
            cout << cat;
            break;
        }
        case 7:
        {
            mgMachine *machine1 = mg_newmachine();
            mgMachine *machine2 = mg_newmachine();
            if (mg_are_equal(machine1, machine2) == 0)
            {
                cout << endl
                     << "The 2 machines selected are identical" << endl;
            }
            else
            {
                cout << endl
                     << "The 2 machines selected are different" << endl;
            }
            mg_destroyM(machine1);
            mg_destroyM(machine2);
            break;
        }
        case 8:
        {
            cat = "";
            break;
        }
        case 9:
        {
            mg_destroyM(lanciamacc);

            cat = "";
            cout << endl
                 << "Program ended" << endl;
            break;
        }
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
    return 0;
}