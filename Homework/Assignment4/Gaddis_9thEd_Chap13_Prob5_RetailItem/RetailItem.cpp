/* 
 * File:   RetailItem.h
 * Author: John Haller
 *
 * Created on November 5, 2018, 5:59 PM
 */

#include "RetailItem.h"

//Invntry(string,int,float);
//    string getDesc()const;
//    int getUnit()const;
//    float getPrce()const;

Invntry::Invntry(string name,int num,float cost){
    descrpt=name;
    units=num;
    price=cost;
}
string Invntry::getDesc() const{
    return descrpt;
}
int Invntry::getUnit() const{
    return units;
}
float Invntry::getPrce() const{
    return price;
}