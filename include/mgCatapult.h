#ifndef MGCATAPULT_H
#define MGCATAPULT_H

#include <iostream>
#include <string>
 
struct mgCatapult
{
    float arm,alfa,hbox,hbase,rad;
};

void mg_init_cat(mgCatapult* catapulta);
void mg_check(mgCatapult* catapulta);
#endif