
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
    friend class Player;
private:
    int nBombs;
    char **bField;
public:
    Bomb (int bombs):Player(nRows,nCols){
        this->rows=nRows;
        this->cols=nCols;
        nBombs=bombs;
        makeBF();
        setBomb();
    };
    void makeBF();//allocates bField
    int getRows()const{
        return this->rows;
    }
    int getCols()const{
        return this->cols;
    }
    char getBomb(int i,int j)const{
    if(i<0)return ' ';
    if(j<0)return ' ';
    if(i>this->rows-1)return ' ';
    if(j>this->cols-1)return ' ';
    return bField[i][j];
    }
    void print();
    void filBomb();//Fills bomb field with 'X'
    void setBomb();//Fills in bombs
    ~Bomb();
};

#endif /* BOMBFLD_H */

