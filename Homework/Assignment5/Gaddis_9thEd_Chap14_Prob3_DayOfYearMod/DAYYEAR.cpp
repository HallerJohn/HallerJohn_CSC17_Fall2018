/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DAYYEAR.h"
#include <iostream>
using namespace std;

DayYear::DayYear(){
    addDay(day,month);
    setMnth(day);
    cout<<"That would be ";
    print();
}

DayYear::DayYear(int num){
    cout<<"Day "<<num<<" would be ";
    setMnth(num);
    print();
}

DayYear::DayYear(int num, string month){
    addDay(num,month);
    setMnth(num);
    cout<<"That would be ";
    print();
}

DayYear DayYear::operator ++(){
    ++day;
    return *this;
}

void DayYear::addDay(int &num,string month){
    if(month=="january"&&num>31)error();
    if(month=="february"){
        if(num>28)error();
        num+=31;
    }
    else if(month=="march"){
        if(num>31)error();
        num+=59;
    }
    else if(month=="april"){
        if(num>30)error();
        num+=90;
    }
    else if(month=="may"){
        if(num>31)error();
        num+=120;
    }
    else if(month=="june"){
        if(num>30)error();
        num+=151;
    }
    else if(month=="july"){
        if(num>31)error();
        num+=181;
    }
    else if(month=="august"){
        if(num>31)error();
        num+=212;
    }
    else if(month=="september"){
        if(num>30)error();
        num+=243;
    }
    else if(month=="october"){
        if(num>31)error();
        num+=273;
    }
    else if(month=="november"){
        if(num>30)error();
        num+=304;
    }
    else if(month=="december"){
        if(num>31)error();
        num+=334;
    }
}

void DayYear::setMnth(int num){
    day=num;
    if(num>=335){
        month="December";
        day-=334;
    }
    else if(num>=305&&num<=334){
        month="November";
        day-=304;
    }
    else if(num>=274&&num<=304){
        month="October";
        day-=273;
    }
    else if(num>=244&&num<=273){
        month="September";
        day-=243;
    }
    else if(num>=213&&num<=273){
        month="August";
        day-=212;
    }
    else if(num>=182&&num<=212){
        month="July";
        day-=181;
    }
    else if(num>=152&&num<=181){
        month="June";
        day-=151;
    }
    else if(num>=121&&num<=151){
        month="May";
        day-=120;
    }
    else if(num>=91&&num<=120){
        month="April";
        day-=90;
    }
    else if(num>=60&&num<=90){
        month="March";
        day-=59;
    }
    else if(num>=32&&num<=59){
        month="February";
        day-=31;
    }
    else {
        month="January";
    }
}
void DayYear::print(){
    cout<<month<<" "<<day<<endl;
}
void DayYear::error(){
    cout<<"Invalid day";
    exit(EXIT_FAILURE);
}