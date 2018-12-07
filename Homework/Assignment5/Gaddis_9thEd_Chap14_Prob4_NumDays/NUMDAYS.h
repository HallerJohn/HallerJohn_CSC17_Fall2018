/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NUMDAYS.h
 * Author: John Haller
 *
 * Created on November 12, 2018, 6:26 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays{
private:
    int hours;
    float days;
public:
    NumDays(int hour){
        setHour(hour);
        setDays();
    }
    NumDays (){
        hours=0;
        days=0;
    }
    NumDays operator+(const NumDays&);
    void setHour(int hour){
        hours=hour;
    }
    void setDays(){
        days=hours/8.0f;
    }
    int getHour()const{
        return hours;
    }
    float getDays()const{
        return days;
    }
    void print();
};

#endif /* NUMDAYS_H */

