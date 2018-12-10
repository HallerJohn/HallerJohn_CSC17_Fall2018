
/* 
 * File:   BOMBFLD.h
 * Author: John Haller
 *
 * Created on November 19, 2018, 11:50 PM
 */

#ifndef BOMBFLD_H
#define BOMBFLD_H
#include <iostream>
#include "PLAYFLD.h"

//This is the Bomb class inherited from Field.
//The purpose of this class is to hold info for the location of bombs
class Bomb : public Field{
private:
    //Number of bombs
    int nBombs;
public:
    //Constructor sets members and drives the creation of the bomb field
    //There was a reason i had this here and not in the .cpp file
    //but i have long forgotten why
    Bomb (int nRows,int nCols,int bombs){
        this->rows=nRows;
        this->cols=nCols;
        nBombs=bombs;
        makeF();
        filFld();
        setBomb();
    };
    virtual int getRow()const{
        return rows;
    }
    virtual int getCol()const{
        return cols;
    }
    void makeF();//Allocates BField
    void filFld();//Fills bomb array with 'X'
    char getBomb(int,int)const;//Returns the character of chosen tile for comparrison
    void setBomb();//Fills in bombs
    ~Bomb();//destructor
};

#endif /* BOMBFLD_H */

