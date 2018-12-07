

/* 
 * File:   PLAYFLD.h
 * Author: John Haller
 *
 * Created on November 20, 2018, 10:09 AM
 */

#ifndef PLAYFLD_H
#define PLAYFLD_H

class Player{
private:
    int pRows;
    int pCols;
    char **pField;
public:
    Player(int,int);
    int getRows()const{
        return pRows;
    }
    int getCols()const{
        return pCols;
    }
    void setPFld(int i,int j,char tile){
        pField[i][j]=tile;
    }
    char getPlay(int i,int j){
        return pField[i][j];
    }
    void makePF();//Allocates pField
    void filPlay();//Fills player array with 'X'
    void prtPlay();
};

#endif /* PLAYFLD_H */

