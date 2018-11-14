/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DAYYEAR.h"
#include <iostream>
using namespace std;


DayYear::DayYear(int num){
    cout<<"Day "<<num<<" would be ";
    setMnth(num);
    print();
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