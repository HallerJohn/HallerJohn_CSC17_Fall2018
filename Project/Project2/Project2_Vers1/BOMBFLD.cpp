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

Bomb::Bomb(int rows,int cols,int bombs){
    bRows=rows;
    bCols=cols;
    nBombs=bombs;
    makeBF();
    setBomb();
}

Bomb::~Bomb(){
    for (int i = 0 ; i < bRows ; i++){
        delete bField[i];
    }
    delete []bField;
}

void Bomb::makeBF(){
    char** a=new char*[bRows];
    for(int i = 0; i < bRows; i++){
        a[i]=new char[bCols];
    }
    bField=a;
    filBomb();
}

void Bomb::print(){
    for(int i = 0; i < bRows; i++){
        for(int j = 0; j < bCols; j++){
            cout<<bField[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Bomb::filBomb(){
    for(int i = 0; i < bRows; i++){
        for(int j = 0; j < bCols; j++){
            bField[i][j]='X';
        }
    }
}

void Bomb::setBomb(){
    //Set random number seed
    srand(static_cast <unsigned int>(time(0)));
    int bCount = 0;
    do{
        int bRow=rand()%bRows;
        int bCol=rand()%bCols;
        if(bField[bRow][bCol]!='B'){
            bField[bRow][bCol]='B';
            bCount++;
        }
    }while(bCount<nBombs);
}

