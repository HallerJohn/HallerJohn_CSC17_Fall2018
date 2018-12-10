/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FIELD.h
 * Author: John Haller
 *
 * Created on December 8, 2018, 7:51 PM
 */

#ifndef FIELD_H
#define FIELD_H

#include <iostream>

//This is an abstract class used to inherit from.
//The classes inheriting from this are Player, and Bomb
class Field{
protected:
    int rows;
    int cols;
    char **field;
public:
    void poly(){
        if(1<0)std::cout<<"HI"<<std::endl;
    }
    //Virtual functions
    virtual int getRow()const=0;
    virtual int getCol()const=0;
};

#endif /* FIELD_H */

