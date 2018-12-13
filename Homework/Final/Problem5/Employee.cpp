/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(string name,string title, float rate){
    MyName=name;
    JobTitle=title;
    HourlyRate=rate;
    HoursWorked=0;
    GrossPay=0;
    NetPay=0;
}

float Employee::Tax(float grssPay){
    if(grssPay<=500)return grssPay*.1;
    else if(grssPay>500&&grssPay<=1000)return ((grssPay-500)*.2+50);
    else return ((grssPay-1000)*.3+150);
}

void Employee::toString(){
    cout<<"Name: "<<MyName<<"   Title: "<<JobTitle<<endl;
    cout<<"Hourly Rate: "<<HourlyRate<<"    Hours Worked: "<<HoursWorked<<
            "   Gross Pay: "<<GrossPay<<"   Net Pay: "<<NetPay<<endl;
}

float Employee::getGrossPay(float rate, int hours){
    if(hours<=40)GrossPay= rate*hours;
    else if(hours>40&&hours<=50)GrossPay = 1.5*rate*(hours-40)+(40*rate);
    else GrossPay = 2*(rate*(hours-50))+(1.5*10*rate)+(40*rate);
    return GrossPay;
}

float Employee::getNetPay(float){
    NetPay=GrossPay-Tax(GrossPay);
}

float Employee::CalculatePay(float x, int y){
    return getNetPay(getGrossPay(setHourlyRate(x)
		,setHoursWorked(y)));
}