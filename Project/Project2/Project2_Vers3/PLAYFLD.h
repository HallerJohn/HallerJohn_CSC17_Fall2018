

/* 
 * File:   PLAYFLD.h
 * Author: John Haller
 *
 * Created on November 20, 2018, 10:09 AM
 */

#ifndef PLAYFLD_H
#define PLAYFLD_H
#include "FIELD.h"

//Class used for the player field, which the player can see and interract with,
//this class is inherited from the Field class.
class Player :public Field{
public:
    Player ();
    //Sets members inherited from Field
    Player(int,int);
    //Returns number of rows
    int getRow()const{
        return rows;
    }
    //Returns number of cols
    int getCol()const{
        return cols;
    }
    //Sets the value of chosen tile
    void setFld(int i,int j,char tile){
        field[i][j]=tile;
    }
    //Gets the value of the chosen tile
    char getFld(int i,int j)const{
        return field[i][j];
    }
    void makeF();//Allocates pField
    void filFld();//Fills player array with 'X'
    void prtFld();//Prints the player field
     ~Player();
};

#endif /* PLAYFLD_H */

