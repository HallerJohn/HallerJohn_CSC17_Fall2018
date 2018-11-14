/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NUMBERS.h
 * Author: John Haller
 *
 * Created on November 12, 2018, 2:56 PM
 */

#include <string>
#include <iostream>
using namespace std;

#ifndef NUMBERS_H
#define NUMBERS_H

class Numbers{
private:
    int number;
    string answer;
public:
    Numbers();
    void convert();
    string one(int i){
        string ones[9]={
        "one","two","three","four","five","six","seven","eight","nine"
        };
        return ones[i];
    }
    string spec(int i){
        string special[10]={
        "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen",
        "seventeen","eighteen","nineteen"
        };
        return special[i];
    }
    string ten(int i){
        string tens[8]={
        "twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"
        };
        return tens[i];
    }
};

#endif /* NUMBERS_H */

