/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Popu.h
 * Author: rcc
 *
 * Created on November 8, 2018, 12:19 PM
 */

#ifndef POPU_H
#define POPU_H

class Pop{
private:
    int nPeople;
    int nDied;
    int nBorn;
public:
    Pop(int people,int died,int born){
        nPeople=people;
        nDied=died;
        nBorn=born;
    }
    float birth(){
        return nBorn/static_cast<float>(nPeople);
    }
    float death(){
        return nDied/static_cast<float>(nPeople);
    }
    int getPeop()const{
        return nPeople-nDied+nBorn;
    }
};

#endif /* POPU_H */

