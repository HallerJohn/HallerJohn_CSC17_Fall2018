/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SPRVSR.h
 * Author: John Haller
 *
 * Created on November 26, 2018, 1:37 AM
 */
#include "EMPLOYEE.h"

#ifndef SPRVSR_H
#define SPRVSR_H

class Sprvsr : public Emplyee{
private:
    float salary;
    float bonus;
public:
    void setSlry(){
        cin>>salary;
    }
    void setBns(){
        cin>>bonus;
    }
    float getSlry(){
        return salary;
    }
    float getBns(){
        return bonus;
    }
    
};

#endif /* SPRVSR_H */

