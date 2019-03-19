/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PROB1.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


Prob1Random::Prob1Random(const char n, const char*rndseq){
    set=new char(n);
    freq=new int(n);
    for(int i=0;i<n;i++){
        set[i]=rndseq[i];
        freq[i]=0;
    }
    nset=n;
    numRand=0;
}

Prob1Random::~Prob1Random(){
    delete set;
    delete freq;
}

char Prob1Random::randFromSet(){
    int x=rand()%5;
    freq[x]++;
    numRand++;
    return set[x];
}
int *Prob1Random::getFreq() const{
    return freq;
}

char *Prob1Random::getSet() const{
    return set;
}

int Prob1Random::getNumRand() const{
    return numRand;
}
