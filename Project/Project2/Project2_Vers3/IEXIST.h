/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IEXIST.h
 * Author: John Haller
 *
 * Created on December 8, 2018, 3:09 PM
 */

#ifndef IEXIST_H
#define IEXIST_H

#include "AGGREGATE.h"


//This class is used to demonstrate that i know how to do things that i didn't
//find a use for in my project
class IExist{
private:
    //Variable used for the top secret thing in main
    int x;
    //Counter for objects used above top secret thing
    static int oCount;
    //The place where i used aggregation
    Aggregate important;
public:
    IExist(){
        //Initialize members to 0
        oCount=0;
        x=0;
    }
    //Overloaded operator for top secret thing
    IExist operator++(){
        x++;
        return *this;
    }
    IExist operator--(){
        x--;
        return *this;
    }
    //Another overloaded operator for top secret thing
    bool operator<(int y){
        if(x<y)return true;
        return false;
    }
    //Setting member for top secret thing
    void setX(int z){
        x=z;
    }
    //Returning x for top secret thing
    int getX()const{
        return x;
    }
    //Returns counter for objects
    int getCnt()const{
        return oCount;
    }
    //Used to increment counter of objects
    void incCnt(){
        oCount++;
    }
};

#endif /* IEXIST_H */

