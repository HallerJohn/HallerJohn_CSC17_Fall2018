/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Date.h"

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

Date::Date(){
    setMnth();
    setDay();
    setYear();
}
void Date::setMnth(){
    cin>>Month;
    if(Month>12||Month<1){
        cout<<"Invalid month input"<<endl;
        exit(EXIT_FAILURE);
    }
    engMnth=setEngM();
}
void Date::setDay(){
    cin>>Day;
    if(Day>31||Day<1){
        cout<<"Invalid day input"<<endl;
        exit(EXIT_FAILURE);
    }
}
void Date::setYear(){
    cin>>Year;
}
string Date::setEngM(){
    static string months[]={"January","February","March","April","May","June",
        "July","August","September","October","November","December"};
    return months[Month-1];
}
void Date::print1(){
    cout<<Month<<"/"<<Day<<"/"<<Year<<endl;
}
void Date::print2(){
    cout<<engMnth<<" "<<Day<<", "<<Year<<endl;
}
void Date::print3(){
    cout<<Day<<" "<<engMnth<<" "<<Year<<endl;
}