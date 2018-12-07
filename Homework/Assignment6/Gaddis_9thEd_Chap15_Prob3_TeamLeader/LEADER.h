/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LEADER.h
 * Author: John Haller
 *
 * Created on November 26, 2018, 1:43 AM
 */
#include "EMPLOYEE.h"

#ifndef LEADER_H
#define LEADER_H

class Leader : public Emplyee{
private:
    int bonus;
    int hrsReq;
    int hrsDone;
public:
    void setBns(){
        cin>>bonus;
    }
    void setReq(){
        cin>>hrsReq;
    }
    void setDone(){
        cin>>hrsDone;
    }
    int getBns(){
        return bonus;
    }
    int getReq(){
        return hrsReq;
    }
    int getDone(){
        return hrsDone;
    }
};

#endif /* LEADER_H */

