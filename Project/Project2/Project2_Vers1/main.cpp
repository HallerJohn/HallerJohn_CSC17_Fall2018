/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "BOMBFLD.h"
#include "PLAYFLD.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void intro();
void choice(char &,int &,int &);
void check(Player *,Bomb *,int,int);
void fndBomb(Player *,Bomb *,int,int);
void recurs(Player *,Bomb *,int,int);
void death(Player *);
void flag(Player *,Bomb *,int,int,int &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Variables
    int rows;
    int cols;
    int bombs;
    int chosenR;
    int chosenC;
    char command;
    int flagCnt=0;
    
    //Intro
    intro();
    
    //Input size of grid and number of bombs
    cout<<"We will now construct your minefield."<<endl;
    cout<<"How many rows would you like in your field?"<<endl;
    cin>>rows;
    cout<<"How many cols would you like in your field?"<<endl;
    cin>>cols;
    cout<<"How many bombs woulds you like to play with?"<<endl;
    cin>>bombs;
    
    //Create pointer to Bomb and Player field
    Bomb *bPoint=new Bomb(rows,cols,bombs);
    Player *pPoint=new Player(rows,cols);
    
    //Print bomb field for testing
//    bPoint->print();
    pPoint->prtPlay();
    
    
    //Loop to play game
    do{
        //input players decision
        choice(command,chosenR,chosenC);

        //If player selects a tile
        if(command=='s'){
            check(pPoint,bPoint,chosenR,chosenC);
            pPoint->prtPlay();
        }else if(command=='f'){
            flag(pPoint,bPoint,chosenR,chosenC,flagCnt);
        }
        
    }while(flagCnt!=bombs);
    
    //If you made it here you have won
    cout<<"Congratulations you have won JOHNSWEEPER!"<<endl;
    
    //Delete pointer to Bomb
    delete bPoint;
    delete pPoint;
    
    //Exit stage right!
    return 0;
}

void choice(char &command,int &chosenR,int &chosenC){
    cout<<"What action would you like to take?"<<endl;
    cin>>command>>chosenR>>chosenC;
    chosenR-=1;
    chosenC-=1;
}

void check(Player *pPoint,Bomb *bPoint,int chosenR,int chosenC){
    if(bPoint->getBomb(chosenR,chosenC)=='B'){
        pPoint->setPFld(chosenR,chosenC,'B');
        death(pPoint);
    }
    else if(bPoint->getBomb(chosenR,chosenC)=='X'){
        fndBomb(pPoint,bPoint,chosenR,chosenC);
    }
}

void fndBomb(Player *pPoint,Bomb *bPoint,int row,int col){
    if(pPoint->getPlay(row,col)!=' '){
        char bombCnt=0;
        if(bPoint->getBomb(row-1,col-1)=='B')bombCnt++;
        if(bPoint->getBomb(row-1,col)=='B')bombCnt++;
        if(bPoint->getBomb(row-1,col+1)=='B')bombCnt++;
        if(bPoint->getBomb(row,col-1)=='B')bombCnt++;
        if(bPoint->getBomb(row,col+1)=='B')bombCnt++;
        if(bPoint->getBomb(row+1,col-1)=='B')bombCnt++;
        if(bPoint->getBomb(row+1,col)=='B')bombCnt++;
        if(bPoint->getBomb(row+1,col+1)=='B')bombCnt++;

        if(bombCnt==0){
            pPoint->setPFld(row,col,' ');
            recurs(pPoint,bPoint,row,col);
        }
        else{
            pPoint->setPFld(row,col,bombCnt+48);
        }
    }
}
void recurs(Player *pPoint,Bomb *bPoint,int row,int col){
    check(pPoint,bPoint,row-1,col);
    check(pPoint,bPoint,row,col-1);
    check(pPoint,bPoint,row,col+1);
    check(pPoint,bPoint,row+1,col);
}

void death(Player *pPoint){
    pPoint->prtPlay();
    cout<<"You hit a bomb and died, rip."<<endl;
    exit(EXIT_FAILURE);
}

void flag(Player *pPoint,Bomb *bPoint,int row,int col,int &flagCnt){
    if(pPoint->getPlay(row,col)=='F')pPoint->setPFld(row,col,'X');
    else pPoint->setPFld(row,col,'F');
    if(bPoint->getBomb(row,col)=='B')flagCnt++;
    pPoint->prtPlay();
}

void intro(){
    cout<<"Welcome to JOHNSWEEPER!"<<endl;
    cout<<"The objective is to flag all of the tiles that "
            <<"contain a bomb"<<endl;
    cout<<"First you will input how many bombs you "
            <<"want to play with. "<<endl;
    cout<<"Next select a tile"<<endl;
    cout<<"You do this by entering your action, 's' for select, "
            <<"or 'f' for flag"<<endl;
    cout<<"Follow your action with a space and then a number "
            <<"for what row you want to select"<<endl;
    cout<<"Followed by another space and a number for what "
            <<"column you want"<<endl;
    cout<<"An example input is [s 4 5]"<<endl<<endl;
}