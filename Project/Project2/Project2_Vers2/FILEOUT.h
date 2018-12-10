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

class FileOut{
private:
    int games;
    int turn;
    int row;
    int col;
    char action;
public:
    FileOut(int);
    void setGame(int game){
        games=game;
    }
    void incTurn(){
        turn++;
    }
    int getGame()const{
        return games;
    }
    void setRow(int x){
        row=x;
    }
    void setCol(int x){
        col=x;
    }
    void setAct(char x){
        action=x;
    }
    int getTurn()const{
        return turn;
    }
    int getRow()const{
        return row;
    }
    int getCol()const{
        return col;
    }
    char getAct()const{
        return action;
    }
};

#endif /* FILEOUT_H */

