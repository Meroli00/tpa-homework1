#include "../include/catch2/catch2.hpp"
#include "../include/mgCatapult.h"

TEST_CASE("mg_check dovrebbe restituire val=0 se i valori sono corretti","[mgCatapult]"){
    mgCatapult* catapulta = mg_newcat();

    catapulta->rad = -40;    //negativo
    catapulta->hbase = 60;  
    catapulta->hbox = 70;
    catapulta->arm = 450;
    catapulta->alfa = 80; 

    REQUIRE(mg_check(catapulta) == 1);

    delete(catapulta);
}

TEST_CASE("mg_check dovrebbe restituire val=1 per violazione dei vincoli su alfa","[mgCatapult]"){
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
    mgCatapult* catapulta = mg_newcat();

    catapulta->rad = -40;    //negativo
    catapulta->hbase = 60;  
    catapulta->hbox = 70;
    catapulta->arm = 450;
    catapulta->alfa = 80; 

    REQUIRE(mg_check(catapulta) == 1);

    delete(catapulta);
}

TEST_CASE("dovrebbe eliminare l'oggetto catapulta","[mgCatapult]"){
    mgCatapult* catapulta = mg_newcat();

    mg_destroy(catapulta);

    REQUIRE(catapulta == NULL);
}