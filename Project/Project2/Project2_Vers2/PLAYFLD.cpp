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


Player::Player(int nrows,int nCols){
    rows=nrows;
    cols=nCols;
    makeF();
    filFld();
}

void Player::makeF(){
    char **a=new char*[rows];
    for(int i = 0;i < rows;i++){
        a[i]=new char[cols];
    }
    field=a;
}

void Player::filFld(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            field[i][j]='X';
        }
    }
}

void Player::prtFld(){
    std::cout<<"    ";
    for(int i=0;i<cols;i++){
        std::cout<<i+1;
        if(i+1<10)std::cout<<" ";
    }
    std::cout<<std::endl<<"    ";
    for(int i=0;i<cols;i++){
        std::cout<<"--";
    }
    std::cout<<std::endl;
    for(int i = 0; i < rows; i++){
        std::cout<<std::setw(2)<<i+1<<"| ";
        for(int j = 0; j < cols; j++){
            std::cout<<field[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
Player::~Player(){
    for(int i=0; i<rows;i++){
        delete field[i];
    }
    delete field;
}
