#include "../include/catch2/catch2.hpp"
#include "../include/mgCatapult.h"

TEST_CASE("mg_tot_check dovrebbe restituire val=0 perche tutti i valori sono corretti","[mgCatapult]"){
    cout << endl << "TEST 0:" << endl;
    mgCatapult* catapulta = mg_newcat();

    catapulta->rad = 40;   
    catapulta->hbase = 60;  
    catapulta->hbox = 70;
    catapulta->arm = 450;
    catapulta->alfa = 50; 

    REQUIRE(mg_tot_check(catapulta) == 0);

    delete(catapulta);
}
TEST_CASE("mg_tot_check dovrebbe restituire val=1 perche red < 20","[mgCatapult]"){
    cout << endl << "TEST 1:" << endl;
    mgCatapult* catapulta = mg_newcat();

    catapulta->rad = 0;    // < 20 !!
    catapulta->hbase = 60;  
    catapulta->hbox = 70;
    catapulta->arm = 450;
    catapulta->alfa = 80; 

    REQUIRE(mg_tot_check(catapulta) == 1);

    delete(catapulta);
}

TEST_CASE("mg_tot_check dovrebbe restituire val=1 per violazione dei vincoli su alfa","[mgCatapult]"){
    cout << endl << "TEST 2:" << endl;
    mgCatapult* catapulta = mg_newcat();

    catapulta->rad = 40;
    catapulta->hbase = 60;
    catapulta->hbox = 70;
    catapulta->arm = 450;
    catapulta->alfa = 180;  //troppo grande

    REQUIRE(mg_tot_check(catapulta) == 1);

    delete(catapulta);
}

TEST_CASE("mg_tot_check dovrebbe restituire val=1 per violazione dei vincoli su hbase","[mgCatapult]"){
    cout << endl << "TEST 3: " << endl;
    mgCatapult* catapulta = mg_newcat();

    catapulta->rad = 40;
    catapulta->hbase = 160;  //troppo grande
    catapulta->hbox = 70;
    catapulta->arm = 450;
    catapulta->alfa = 80; 

    REQUIRE(mg_tot_check(catapulta) == 1);

    delete(catapulta);
}

TEST_CASE("mg_tot_check dovrebbe restituire val=1 per violazione dei vincoli su rad","[mgCatapult]"){
    cout << endl << "TEST 4: " << endl;
    mgCatapult* catapulta = mg_newcat();

    catapulta->rad = -40;    //negativo
    catapulta->hbase = 60;  
    catapulta->hbox = 70;
    catapulta->arm = 450;
    catapulta->alfa = 80; 

    REQUIRE(mg_tot_check(catapulta) == 1);

    delete(catapulta);
}

