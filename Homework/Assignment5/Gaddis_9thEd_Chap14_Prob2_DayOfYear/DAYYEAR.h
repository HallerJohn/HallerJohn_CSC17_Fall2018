/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DAYYEAR.h
 * Author: John Haller
 *
 * Created on November 12, 2018, 4:27 PM
 */

#include <string>
using namespace std;

#ifndef DAYYEAR_H
#define DAYYEAR_H

class DayYear{
private:
    string date;
    int day;
    string month;
public:
    DayYear(int);
    void setMnth(int);
    void print();
    
};

#endif /* DAYYEAR_H */

