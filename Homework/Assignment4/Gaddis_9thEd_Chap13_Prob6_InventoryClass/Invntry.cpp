/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Invntry.h"
#include <iostream>
using namespace std;


Invntry::Invntry(){
    cout<<"HI"<<endl;
    itemNum=0;
    quanty=0;
    cost=0;
    totCost=0;
}
Invntry::Invntry(int num,int quant, float price){
    setINum(num);
    setQnt(quant);
    setCost(price);
    setTotC();
}