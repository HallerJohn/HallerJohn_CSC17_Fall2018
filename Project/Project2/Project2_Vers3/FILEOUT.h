/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FILEOUT.h
 * Author: John Haller
 *
 * Created on December 7, 2018, 2:59 PM
 */

#ifndef FILEOUT_H
#define FILEOUT_H
#include <iostream>
using namespace std;

//This class is used strictly for writing to files
class FileOut{
private:
    //Counter for number of games played
    int games;
    //Counter for what turn it is
    int turn;
    //Chosen row
    int row;
    //Chosen col
    int col;
    //Action input (f,s)
    char action;
public:
    FileOut(int);
    //Sets the number of game being played
    void setGame(int game){
        games=game;
    }
    //used to increment turn
    void incTurn(){
        turn++;
    }
    //Returns game number
    int getGame()const{
        return games;
    }
    //Sets chosen row
    void setRow(int x){
        row=x;
    }
    //Sets chosen col
    void setCol(int x){
        col=x;
    }
    //Sets selected action
    void setAct(char x){
        action=x;
    }
    //Returns current turn
    int getTurn()const{
        return turn;
    }
    //Returns chosen row
    int getRow()const{
        return row;
    }
    //Returns chosen col
    int getCol()const{
        return col;
    }
    //Returns chosen action
    char getAct()const{
        return action;
    }
};

#endif /* FILEOUT_H */

