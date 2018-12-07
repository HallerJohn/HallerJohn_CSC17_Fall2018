/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NUMBERS.h"
#include <iostream>
using namespace std;




Number Number::operator +(const Number &right){
    Number temp;
    temp.number= number+right.number;
    return temp;
}


Number Number::operator -(const Number &right){
    Number temp;
    temp.number=number-right.number;
    return temp;
}


bool Number::operator ==(const Number &right){
    if(number==right.number)return true;
    return false;
}


Number Number::operator ++(){
    ++number;
    return *this;
}

//Number Number::operator ++(int){
//    Number temp(number);
//    number++;
//    cout<<"Temp number = "<<temp.number<<endl;
//    return temp;
//}

Number Number::operator ++(int){
    number++;
    return *this;
}
Number Number::operator --(){
    --number;
    return *this;
}
Number Number::operator --(int){
    Number temp(number);
    number--;
    return temp;
}

bool Number::operator >(const Number &right){
    if(number > right.number)return true;
    return false;
}

bool Number::operator <(const Number &right){
    if(number < right.number)return true;
    return false;
}
