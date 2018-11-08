/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TstScre.h
 * Author: rcc
 *
 * Created on November 8, 2018, 10:53 AM
 */

#ifndef TSTSCRE_H
#define TSTSCRE_H

#include <iostream>
using namespace std;

class TstScre{
private:
    float *scores;
    float avgScre;
public:
    TstScre(float *);
    void setScre(float,int);
    void setAvgS();
    float getAvgS()const{
        return avgScre;
    }
    float getScre(int i)const{
        return scores[i];
    }
    void cleanup(){
        delete scores;
    }
};

#endif /* TSTSCRE_H */

