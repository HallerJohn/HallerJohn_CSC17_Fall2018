/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Bomb.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
const int COLS=12;//Two more than necessary to have border

//Function Prototypes
char **initAry(int,int);
Bomb *filStrc(char **,int,int);
void fillAry(Bomb *,char [][COLS]);
void copyAry(char [][COLS],Bomb *);
void prntAry(char [][COLS],int);
void prntAry(Bomb *);
void choice(Bomb *,char [][COLS],int);
void bombs(Bomb *);
void cntBomb(Bomb*);
bool check(Bomb *,int,int,char [][COLS]);
void reveal(Bomb *,int,int,char [][COLS]);
void death();

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int rows=12;//Two more than necessary for border
    int cols=12;
    char playAry[rows][COLS];
    char **dynAry=initAry(rows,cols);
    Bomb *array2D=filStrc(dynAry,rows,cols);
    
    //Fill and Print array
    initAry(rows,cols);
    fillAry(array2D,playAry);
    prntAry(playAry,rows);
//    prntAry(array2D);
    cntBomb(array2D);
    
    //Choose a position
    choice(array2D,playAry,rows);
    //Initialize Variables
    
    //Process/Map inputs to outputs
    
    //Output data
    
    //Exit stage right!
    return 0;
}
char **initAry(int row, int col){
    char **a=new char*[row];
    for(int i=0;i<row;i++){
        a[i]=new char[col];
    }
    for(int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            a[i][j]='b';
        }
    }
    return a;
}
Bomb *filStrc(char **a,int row,int col){
    Bomb *d2=new Bomb;
    d2->rows=row;
    d2->cols=col;
    (*d2).bombAry=a;
    return d2;
    
}
void fillAry(Bomb *d2,char playAry[][COLS]){
    for(int row=1;row<d2->rows-1;row++){
        for(int col=1;col<d2->cols-1;col++){
            d2->bombAry[row][col]='X';
        }
    }
    copyAry(playAry,d2);
    bombs(d2);
}
void copyAry(char playAry[][COLS],Bomb *d2){
    for(int i=0;i<d2->rows;i++){
        for(int j=0;j<d2->cols;j++){
            playAry[i][j]=d2->bombAry[i][j];
        }
    }
}
void prntAry(char playAry[][COLS],int rows){
    cout<<setw(4)<<' ';
    for(int i=1;i<COLS-1;i++){
        if(i==10)cout<<' ';
        cout<<setw(2)<<i;
    }
    cout<<endl;
    for(int i=0;i<COLS-1;i++){
        if(i==0)cout<<setw(2)<<" ";
        cout<<setw(2)<<'-';
    }
    cout<<endl;
    for(int row=1;row<rows-1;row++){
        cout<<setw(2)<<row;
        cout<<setw(2)<<'|';
        for(int col=1;col<COLS-1;col++){
             cout<<setw(2)<<playAry[row][col];
        }
        cout<<endl;
    }
    cout<<endl;
}
void prntAry(Bomb *d2){
    cout<<setw(4)<<' ';
    for(int i=1;i<d2->cols-1;i++){
        if(i==10)cout<<' ';
        cout<<setw(2)<<i;
    }
    cout<<endl;
    for(int i=0;i<d2->cols-1;i++){
        if(i==0)cout<<setw(2)<<" ";
        cout<<setw(2)<<'-';
    }
    cout<<endl;
    for(int row=1;row<d2->rows-1;row++){
        cout<<setw(2)<<row;
        cout<<setw(2)<<'|';
        for(int col=1;col<d2->cols-1;col++){
             cout<<setw(2)<<d2->bombAry[row][col];
        }
        cout<<endl;
    }
    cout<<endl;
}
void choice(Bomb *d2,char playAry[][COLS],int rows){
    bool live=true;
    char action;
    int chseRow;
    int chseCol;
    cin>>action>>chseRow>>chseCol;
    if(action=='f'){
        playAry[chseRow][chseCol]='F';
    }else if(action=='s'){
        live=check(d2,chseRow,chseCol,playAry);
    }
//    if(live)reveal(a,chseRow,chseCol);
    if(!live)return;
    prntAry(playAry,rows);
}
void bombs(Bomb *d2){
    cout<<"How many bombs do you want in your game?"<<endl;
    cin>>d2->nBombs;
    for(int bombs=0;bombs<(d2->nBombs);bombs++){
        int bombRow=rand()%10+1;
        int bombCol=rand()%10+1;
        if(d2->bombAry[bombRow][bombCol]=='B'){
            bombs-=1;
        }
        d2->bombAry[bombRow][bombCol]='B';
    }
}
void cntBomb(Bomb *d2){
    int count=0;
    for(int row=1;row<d2->rows-1;row++){
        for(int col=1;col<d2->cols-1;col++){
            if(d2->bombAry[row][col]=='B'){
                count++;
            }
        }
    }
    cout<<"There are "<<count<<" bombs"<<endl;
}
bool check(Bomb *d2,int chceRow,int chceCol,char playAry[][COLS]){
    if(playAry[chceRow][chceCol]!='X')return true;
    int bombCnt=0;
    if(d2->bombAry[chceRow][chceCol]=='B'){
        playAry[chceRow][chceCol]='B';
        death();
        return false;
    }
    if(d2->bombAry[chceRow-1][chceCol-1]=='B')bombCnt++;
    if(d2->bombAry[chceRow-1][chceCol]=='B')bombCnt++;
    if(d2->bombAry[chceRow-1][chceCol+1]=='B')bombCnt++;
    if(d2->bombAry[chceRow][chceCol-1]=='B')bombCnt++;
    if(d2->bombAry[chceRow][chceCol+1]=='B')bombCnt++;
    if(d2->bombAry[chceRow+1][chceCol-1]=='B')bombCnt++;
    if(d2->bombAry[chceRow+1][chceCol]=='B')bombCnt++;
    if(d2->bombAry[chceRow+1][chceCol+1]=='B')bombCnt++;
    playAry[chceRow][chceCol]=bombCnt+48;
    if(bombCnt==0)playAry[chceRow][chceCol]=' ';
    if(playAry[chceRow][chceCol]==' '){
        reveal(d2,chceRow,chceCol,playAry);
    }
    return true;
}
void reveal(Bomb *d2,int chosRow,int chosCol,char playAry[][COLS]){
    if(playAry[chosRow-1][chosCol]!='B'){
        check(d2,chosRow-1,chosCol,playAry);
    }
    if(playAry[chosRow][chosCol-1]!='B'){
        check(d2,chosRow,chosCol-1,playAry);
    }
    if(playAry[chosRow+1][chosCol]!='B'){
        check(d2,chosRow+1,chosCol,playAry);
    }
    if(playAry[chosRow][chosCol+1]!='B'){
        check(d2,chosRow,chosCol+1,playAry);
    }
    if(playAry[chosRow-1][chosCol-1]!='B'){
        check(d2,chosRow-1,chosCol,playAry);
    }
    if(playAry[chosRow+1][chosCol-1]!='B'){
        check(d2,chosRow,chosCol-1,playAry);
    }
    if(playAry[chosRow-1][chosCol+1]!='B'){
        check(d2,chosRow+1,chosCol,playAry);
    }
    if(playAry[chosRow+1][chosCol+1]!='B'){
        check(d2,chosRow,chosCol+1,playAry);
    }
}
void death(){
    cout<<"dead"<<endl;
}