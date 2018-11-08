/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TstScre.h"
#include <iostream>

using namespace std;


TstScre::TstScre(float *tests){
    scores = new float [3];

    for (int i=0;i<3;i++){
        setScre(tests[i],i);
    }
    avgScre=0;
}
void TstScre::setScre(float score,int i){
    scores[i]=score;
}
void TstScre::setAvgS(){
    for(int i=0;i<3;i++){
        avgScre+=scores[i];
    }
    avgScre/=3;
}