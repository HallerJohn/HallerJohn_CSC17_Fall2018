/* 
 * File:   BOMBFLD.h
 * Author: John Haller
 *
 * Created on November 19, 2018, 11:50 PM
 */

#include <iostream>
#include <cstdlib>
using namespace std;
#include "BOMBFLD.h"


Bomb::~Bomb(){
    for (int i = 0 ; i < this->rows ; i++){
        delete this->field[i];
    }
    delete []this->field;
}

void Bomb::setBomb(){
    //Set random number seed
    srand(static_cast <unsigned int>(time(0)));
    int bCount = 0;
    do{
        int bRow=rand()%this->rows;
        int bCol=rand()%this->cols;
        if(this->field[bRow][bCol]!='B'){
            this->field[bRow][bCol]='B';
            bCount++;
        }
    }while(bCount<nBombs);
}
char Bomb::getBomb(int i,int j)const{
        if(i<0)return ' ';
        if(j<0)return ' ';
        if(i>this->rows-1)return ' ';
        if(j>this->cols-1)return ' ';
        return this->field[i][j];
}

