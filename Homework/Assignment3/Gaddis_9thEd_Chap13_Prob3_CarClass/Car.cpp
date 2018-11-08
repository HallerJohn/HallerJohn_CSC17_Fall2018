/* 
 * File:   Car.h
 * Author: John Haller
 *
 * Created on November 5, 2018, 5:11 PM
 */
#include "Car.h"

Car::Car(int model, string make1){
    yearMdl=model;
    make=make1;
    speed=0;
}
int Car::getMdl() const{
    return yearMdl;
}
string Car::getMake() const{
    return make;
}
int Car::getSped() const{
    return speed;
}
void Car::acclrte(){
    speed+=5;
}
void Car::brake(){
    speed-=5;
}