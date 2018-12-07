/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ESSAY.h
 * Author: John Haller
 *
 * Created on November 26, 2018, 1:54 AM
 */
#include "GRADED.h"
#include <iostream>
using namespace std;

#ifndef ESSAY_H
#define ESSAY_H

class Essay : public Graded{
private:
    int grammar;
    int spelling;
    int length;
    int content;
public:
    Essay();
    void setGram(){
        cin>>grammar;
    }
    void setSpel(){
        cin>>spelling;
    }
    void setLen(){
        cin>>length;
    }
    void setCont(){
        cin>>content;
    }
    int getGram()const{
        return grammar;
    }
    int getSpel()const{
        return spelling;
    }
    int getLen()const{
        return length;
    }
    int getCont(){
        return content;
    }
};

#endif /* ESSAY_H */

