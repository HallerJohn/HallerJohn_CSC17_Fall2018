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

//Destructor deletes the 2D array for the Bomb field
Bomb::~Bomb(){
    for (int i = 0 ; i < this->rows ; i++){
        delete this->field[i];
    }
    delete this->field;
}

//Creates however many bombs the player specifies and randomly inserts them into
//bomb field
void Bomb::setBomb(){
    //Set random number seed
    srand(static_cast <unsigned int>(time(0)));
    //current count of bombs made
    int bCount = 0;
    do{
        //Random row for bomb placement
        int bRow=rand()%this->rows;
        //Random col for bomb placement
        int bCol=rand()%this->cols;
        //Checks to see if bomb has already been place there, if no then places it
        if(this->field[bRow][bCol]!='B'){
            this->field[bRow][bCol]='B';
            //Increments bomb cnt only if a unique location is picked
            bCount++;
        }
    //Loop until all bombs have been made
    }while(bCount<nBombs);
}
//Used to return value of tiles in bomb field
//The if statements are used for accessing tiles out of the bounds of the field
char Bomb::getBomb(int i,int j)const{
    //if negative row
    if(i<0)return ' ';
    //if negative col
    if(j<0)return ' ';
    //If greater row then specified, adjusted with offset
    if(i>this->rows-1)return ' ';
    //if greater col then specified, adjusted with offset
    if(j>this->cols-1)return ' ';
    //If in bounds return value of tile
    return this->field[i][j];
}

//Allocates memory for bomb field
void Bomb::makeF(){
    char **a=new char*[rows];
    for(int i = 0;i < rows;i++){
        a[i]=new char[cols];
    }
    field=a;
}

//Files the bomb field initially with 'X's
void Bomb::filFld(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            field[i][j]='X';
        }
    }
}
