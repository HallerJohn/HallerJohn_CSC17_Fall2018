/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NUMBERS.h
 * Author: rcc
 *
 * Created on November 15, 2018, 11:24 AM
 */

#ifndef NUMBERS_H
#define NUMBERS_H

#include <iostream>
using namespace std;

class Number;

ostream &operator<<(ostream &, const Number &);

class Number{
private:
    int number;
public:
    Number(int i){
        number=i;
    }
    Number(){
        
    }
    Number operator+(const Number &);
    Number operator-(const Number &);
    int getNum(){
        return number;
    }
    bool operator ==(const Number &);
    Number operator++();
//    Number operator++(int);
    Number operator++(int);
    Number operator--();
    Number operator--(int);
    bool operator>(const Number &);
    bool operator<(const Number &);
};



#endif /* NUMBERS_H */

