/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
const int COLS=12;//Two more than necessary to have border

//Function Prototypes
void initAry(char [][COLS],int);
void fillAry(char [][COLS],int);
void prntAry(char [][COLS],int);
void choice(char [][COLS],int);
void bombs(char [][COLS]);
void cntBomb(char [][COLS],int);
bool check(char [][COLS],int,int);
void reveal(char [][COLS],int,int);
void death();

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int rows=12;//Two more than necessary for border
    char array[rows][COLS];
    
    //Fill and Print array
    initAry(array,rows);
    fillAry(array,rows);
    prntAry(array,rows);
    cntBomb(array,rows);
    
    //Choose a position
    choice(array,rows);
    //Initialize Variables
    
    //Process/Map inputs to outputs
    
    //Output data
    
    //Exit stage right!
    return 0;
}
void initAry(char a[][COLS],int rows){
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            a[row][col]='B';
        }
    }
}
void fillAry(char a[][COLS],int rows){
    for(int row=1;row<rows-1;row++){
        for(int col=1;col<COLS-1;col++){
            a[row][col]='X';
        }
    }
    bombs(a);
}
void prntAry(char a[][COLS],int rows){
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
             cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void choice(char a[][COLS],int rows){
    bool live=true;
    char action;
    int chseRow;
    int chseCol;
    cin>>action>>chseRow>>chseCol;
    if(action=='f'){
        a[chseRow][chseCol]='F';
    }else if(action=='s'){
        live=check(a,chseRow,chseCol);
    }
    if(live)reveal(a,chseRow,chseCol);
    if(!live)return;
    prntAry(a,rows);
}
void bombs(char a[][COLS]){
    for(int bombs=0;bombs<10;bombs++){
        int bombRow=rand()%10+1;
        int bombCol=rand()%10+1;
        if(a[bombRow][bombCol]=='B'){
            bombs-=1;
        }
        a[bombRow][bombCol]='B';
    }
}
void cntBomb(char a[][COLS],int rows){
    int count=0;
    for(int row=1;row<rows-1;row++){
        for(int col=1;col<COLS-1;col++){
            if(a[row][col]=='B'){
                count++;
            }
        }
    }
    cout<<"There are "<<count<<" bombs"<<endl;
}
bool check(char a[][COLS],int chceRow,int chceCol){
    int bombCnt=0;
    if(a[chceRow][chceCol]=='B'){
        death();
        return false;
    }
    if(a[chceRow-1][chceCol-1]=='B')bombCnt++;
    if(a[chceRow-1][chceCol]=='B')bombCnt++;
    if(a[chceRow-1][chceCol+1]=='B')bombCnt++;
    if(a[chceRow][chceCol-1]=='B')bombCnt++;
    if(a[chceRow][chceCol+1]=='B')bombCnt++;
    if(a[chceRow+1][chceCol-1]=='B')bombCnt++;
    if(a[chceRow+1][chceCol]=='B')bombCnt++;
    if(a[chceRow+1][chceCol+1]=='B')bombCnt++;
    a[chceRow][chceCol]=bombCnt+48;
    if(bombCnt==0)a[chceRow][chceCol]=' ';
    return true;
}
void reveal(char a[][COLS],int chosRow,int chosCol){
    if(a[chosRow-1][chosCol]!='B'){
        check(a,chosRow-1,chosCol);
        reveal(a,chosRow-1,chosCol);
    }
//    if(a[chosRow+1][chosCol]!='B'){
//        check(a,chosRow+1,chosCol);
//        reveal(a,chosRow+1,chosCol);
//    }
//    if(a[chosRow][chosCol-1]!='B'){
//        check(a,chosRow,chosCol-1);
//        reveal(a,chosRow,chosCol-1);
//    }
    if(a[chosRow][chosCol+1]!='B'){
        check(a,chosRow,chosCol+1);
        reveal(a,chosRow,chosCol+1);
    }
}
void death(){
    cout<<"dead"<<endl;
}