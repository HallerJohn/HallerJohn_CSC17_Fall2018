/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Invntry.h
 * Author: rcc
 *
 * Created on November 8, 2018, 10:27 AM
 */

#ifndef INVNTRY_H
#define INVNTRY_H

class Invntry {
private:
    int itemNum;
    int quanty;
    float cost;
    float totCost;
public:
    Invntry();
    Invntry(int,int,float);
    void setINum(int num){
        itemNum=num;
    }
    void setQnt(int quant){
        quanty=quant;
    }
    void setCost(float price){
        cost=price;
    }
    void setTotC(){
        totCost=quanty*cost;
    }
    int getINum()const{
        return itemNum;
    }
    int getqnt()const{
        return quanty;
    }
    float getCost()const{
        return cost;
    }
    float getTotC()const{
        return totCost;
    }
};

#endif /* INVNTRY_H */

