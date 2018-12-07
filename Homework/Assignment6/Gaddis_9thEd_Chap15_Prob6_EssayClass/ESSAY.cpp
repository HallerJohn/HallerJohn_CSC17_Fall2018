/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ESSAY.h"


Essay::Essay(){
    cout<<"Enter grammar score"<<endl;
    setGram();
    cout<<"Enter spelling score"<<endl;
    setSpel();
    cout<<"Enter length score"<<endl;
    setLen();
    cout<<"Enter content score"<<endl;
    setCont();
    
    
}