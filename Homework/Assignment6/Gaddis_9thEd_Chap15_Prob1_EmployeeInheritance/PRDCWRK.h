/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PRDCWRK.h
 * Author: John Haller
 *
 * Created on November 26, 2018, 1:19 AM
 */
#include "EMPLOYEE.h"

#ifndef PRDCWRK_H
#define PRDCWRK_H

class PrdcWrk : public Emplyee{
private:
    int shift;
    float payRate;
public:
    void setShft(){
        cin>>shift;
    }
    void setRate(){
        cin>>payRate;
    }
    int getShft(){
        return shift;
    }
    float getRate(){
        return payRate;
    }
};

#endif /* PRDCWRK_H */

