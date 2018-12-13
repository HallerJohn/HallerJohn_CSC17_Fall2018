/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: John Haller
 *
 * Created on December 12, 2018, 6:03 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <cstdlib>
#include <iostream>
using namespace std;

class Employee{
private:
    float Tax(float);      //Utility Procedure
    string   MyName;      //Property
    string   JobTitle;    //Property
    float  HourlyRate;      //Property
    int    HoursWorked;     //Property
    float  GrossPay;        //Property
    float  NetPay;          //Property
public:
    Employee(string,string,float);  //Constructor
    float  CalculatePay(float,int); //Procedure
    float  getGrossPay(float,int);
    float  getNetPay(float);
    void   toString();              //Procedure
    int    setHoursWorked(int x){
        if(x<=0||x>=84){
            cout<<"Unacceptable hours workd"<<endl;
        }
        HoursWorked=x;
        return HoursWorked;
    }
    float  setHourlyRate(float x){
        if(x<=0||x>=84){
            cout<<"Unacceptable hourly rate"<<endl;
        }
        HourlyRate=x;
        return HourlyRate;
    }
};

#endif /* EMPLOYEE_H */

