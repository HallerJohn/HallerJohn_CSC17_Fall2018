/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.h
 * Author: John Haller
 *
 * Created on November 2, 2018, 1:38 PM
 */
#include <string>

#ifndef DATE_H
#define DATE_H

class Date{
private:
    int Month;//month input
    int Day;//day input
    int Year;//year input
    std::string engMnth;//English month input
public:
    Date();//constructor calls set functions
    void setMnth();//sets Month
    void setDay();//sets Day
    void setYear();//sets Year
    std::string setEngM();//sets engMnth based on Month
    void print1();//prints first option
    void print2();//prints second option
    void print3();//prints third option
};

#endif /* DATE_H */

