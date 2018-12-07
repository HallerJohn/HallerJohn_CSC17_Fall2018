/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GRADED.h
 * Author: John Haller
 *
 * Created on November 26, 2018, 1:55 AM
 */

#ifndef GRADED_H
#define GRADED_H

class Graded{
private:
    float score;
public:
    Graded(){
        score=0.0;
    }
    Graded(float s){
        score=s;
    }
    void setScre(float s){
        score=s;
    }
    float getScre()const{
        return score;
    }
    char LtrGrade()const;
};

#endif /* GRADED_H */

