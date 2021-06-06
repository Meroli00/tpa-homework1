#include "../include/catch2/catch2.hpp"
#include "../include/mgCatapult.h"

TEST_CASE("mg_check dovrebbe restituire val=0 se i valori sono corretti","[mgCatapult]"){
    cout << endl << "TEST 1: modify wheel radius and type 40" << endl;
    mgCatapult* catapulta = mg_newcat();

    catapulta->rad = 0;    //negativo
    catapulta->hbase = 60;  
    catapulta->hbox = 70;
    catapulta->arm = 450;
    catapulta->alfa = 80; 

    REQUIRE(mg_check(catapulta) == 1);

    delete(catapulta);
}

TEST_CASE("mg_check dovrebbe restituire val=1 per violazione dei vincoli su alfa","[mgCatapult]"){
    cout << endl << "TEST 2: modify the launch angle and type 95 or less" << endl;
    mgCatapult* catapulta = mg_newcat();

    catapulta->rad = 40;
    catapulta->hbase = 60;
    catapulta->hbox = 70;
    catapulta->arm = 450;
    catapulta->alfa = 180;  //troppo grande

    REQUIRE(mg_check(catapulta) == 1);

    delete(catapulta);
}

TEST_CASE("mg_check dovrebbe restituire val=1 per violazione dei vincoli su hbase","[mgCatapult]"){
    cout << endl << "TEST 3: modify base hight and type 60" << endl;
    mgCatapult* catapulta = mg_newcat();

    catapulta->rad = 40;
    catapulta->hbase = 160;  //troppo grande
    catapulta->hbox = 70;
    catapulta->arm = 450;
    catapulta->alfa = 80; 

    REQUIRE(mg_check(catapulta) == 1);

    delete(catapulta);
}

TEST_CASE("mg_check dovrebbe restituire val=1 per violazione dei vincoli su rad","[mgCatapult]"){
    cout << endl << "TEST 4: modify wheel raius and type 40" << endl;
    mgCatapult* catapulta = mg_newcat();

    catapulta->rad = -40;    //negativo
    catapulta->hbase = 60;  
    catapulta->hbox = 70;
    catapulta->arm = 450;
    catapulta->alfa = 80; 

    REQUIRE(mg_check(catapulta) == 1);

    delete(catapulta);
}

