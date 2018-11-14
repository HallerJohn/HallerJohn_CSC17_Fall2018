/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NUMDAYS.h"
#include <iostream>
using namespace std;


void NumDays::print(){
    cout<<"Hours worked :"<<hours<<endl;
    cout<<"Days  worked :"<<days<<endl;
}
NumDays NumDays::operator +(const NumDays &right){
    NumDays temp;
    temp.hours=hours+right.hours;
    return temp;
}