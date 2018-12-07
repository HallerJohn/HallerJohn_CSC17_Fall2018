/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EMPLOYEE.h
 * Author: John Haller
 *
 * Created on November 26, 2018, 1:07 AM
 */
#include <string>
#include <iostream>
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Emplyee{
private:
    string name;
    int number;
    string hireDte;
public:
    Emplyee();
    void setName(){
        cin>>name;
    }
    void setNumb(){
        cin>>number;
    }
    void setDate(){
        cin>>hireDte;
    }
    std::string getName(){
        return name;
    }
    int getNumb(){
        return number;
    }
    std::string getDate(){
        return hireDte;
    }
};

#endif /* EMPLOYEE_H */

