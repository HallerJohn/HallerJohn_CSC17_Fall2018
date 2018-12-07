/* 
 * File:   PLAYFLD.h
 * Author: John Haller
 *
 * Created on November 20, 2018, 10:09 AM
 */

#include "PLAYFLD.h"
#include "BOMBFLD.h"

#include <iostream>
#include <iomanip>


Player::Player(int rows,int cols){
    pRows=rows;
    pCols=cols;
    makePF();
    filPlay();
}

void Player::makePF(){
    char **a=new char*[pRows];
    for(int i = 0;i < pRows;i++){
        a[i]=new char[pCols];
    }
    pField=a;
}

void Player::filPlay(){
    for(int i = 0; i < pRows; i++){
        for(int j = 0; j < pCols; j++){
            pField[i][j]='X';
        }
    }
}

void Player::prtPlay(){
    std::cout<<"    ";
    for(int i=0;i<pCols;i++){
        std::cout<<i+1;
        if(i+1<10)std::cout<<" ";
    }
    std::cout<<std::endl<<"    ";
    for(int i=0;i<pCols;i++){
        std::cout<<"--";
    }
    std::cout<<std::endl;
    for(int i = 0; i < pRows; i++){
        std::cout<<std::setw(2)<<i+1<<"| ";
        for(int j = 0; j < pCols; j++){
            std::cout<<pField[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
