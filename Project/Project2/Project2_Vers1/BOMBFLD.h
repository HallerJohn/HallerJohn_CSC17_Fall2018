
/* 
 * File:   BOMBFLD.h
 * Author: John Haller
 *
 * Created on November 19, 2018, 11:50 PM
 */

#ifndef BOMBFLD_H
#define BOMBFLD_H
#include <iostream>

class Bomb{
    friend class Player;
private:
    int bRows;
    int bCols;
    int nBombs;
    char **bField;
public:
    Bomb (int,int,int);
    void makeBF();//allocates bField
    int getRows()const{
        return bRows;
    }
    int getCols()const{
        return bCols;
    }
    char getBomb(int i,int j)const{
    if(i<0)return ' ';
    if(j<0)return ' ';
    if(i>bRows-1)return ' ';
    if(j>bCols-1)return ' ';
    return bField[i][j];
    }
    void print();
    void filBomb();//Fills bomb field with 'X'
    void setBomb();//Fills in bombs
    ~Bomb();
};

#endif /* BOMBFLD_H */

