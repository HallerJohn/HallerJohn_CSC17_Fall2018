

/* 
 * File:   PLAYFLD.h
 * Author: John Haller
 *
 * Created on November 20, 2018, 10:09 AM
 */

#ifndef PLAYFLD_H
#define PLAYFLD_H

class Player{
protected:
    int rows;
    int cols;
    char **field;
public:
    Player(int,int);
    int getRows()const{
        return rows;
    }
    int getCols()const{
        return cols;
    }
    void setFld(int i,int j,char tile){
        field[i][j]=tile;
    }
    char getFld(int i,int j){
        return field[i][j];
    }
    void makeF();//Allocates pField
    void filFld();//Fills player array with 'X'
    void prtFld();
};

#endif /* PLAYFLD_H */

