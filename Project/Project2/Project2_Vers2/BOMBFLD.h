
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

class Bomb : public Player{
private:
    int nBombs;
public:
    Bomb (int nRows,int nCols,int bombs):Player(nRows,nCols){
        this->rows=nRows;
        this->cols=nCols;
        nBombs=bombs;
        makeF();
        filFld();
        setBomb();
    };
    char getBomb(int,int)const;
    void setBomb();//Fills in bombs
    virtual ~Bomb();
};

#endif /* BOMBFLD_H */

