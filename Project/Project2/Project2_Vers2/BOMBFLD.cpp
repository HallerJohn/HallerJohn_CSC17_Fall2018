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

//Bomb::Bomb(int nRows,int nCols,int bombs){
//    this->rows=nRows;
//    this->cols=nCols;
//    nBombs=bombs;
//    makeBF();
//    setBomb();
//}

Bomb::~Bomb(){
    for (int i = 0 ; i < this->rows ; i++){
        delete bField[i];
    }
    delete []bField;
}

void Bomb::makeBF(){
    char** a=new char*[this->rows];
    for(int i = 0; i < this->rows; i++){
        a[i]=new char[this->cols];
    }
    bField=a;
    filBomb();
}

void Bomb::print(){
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            cout<<bField[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Bomb::filBomb(){
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            bField[i][j]='X';
        }
    }
}

void Bomb::setBomb(){
    //Set random number seed
    srand(static_cast <unsigned int>(time(0)));
    int bCount = 0;
    do{
        int bRow=rand()%this->rows;
        int bCol=rand()%this->cols;
        if(bField[bRow][bCol]!='B'){
            bField[bRow][bCol]='B';
            bCount++;
        }
    }while(bCount<nBombs);
}

