/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.h
 * Author: rcc
 *
 * Created on November 8, 2018, 12:09 PM
 */

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle{
private:
    float radius;
    float pi;
public:
    Circle(){
        radius=0;
        pi=3.14159;
    }
    Circle(float r){
        setRad(r);
        pi=3.14159;
    }
    void setRad(float r){
        radius=r;
    }
    float getRad()const{
        return radius;
    }
    float getArea()const{
        return pi*radius*radius;
    }
    float getDiam()const{
        return radius*2;
    }
    float getCirc()const{
        return 2*pi*radius;
    }
};

#endif /* CIRCLE_H */

