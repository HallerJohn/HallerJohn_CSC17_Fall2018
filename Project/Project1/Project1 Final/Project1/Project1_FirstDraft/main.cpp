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
#include <cstring>
#include <fstream>
using namespace std;

//User Libraries
#include "Bomb.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
const int COLS=12;//Two more than necessary to have border

//Function Prototypes
void intro(string);
char **initAry(int);
Bomb *filStrc(char **,int);
void fillAry(Bomb *,char [][COLS]);
void copyAry(char [][COLS],Bomb *);
void prntAry(char [][COLS],int);
void prntAry(Bomb *);
bool choice(Bomb *,char [][COLS],int,int,int,bool &);
void bombs(Bomb *);
void cntBomb(Bomb*);
bool check(Bomb *,int,int,char [][COLS]);
void reveal(Bomb *,int,int,char [][COLS]);
void death();
bool victory(Bomb *,int,int);
void destroy(Bomb *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //File stuff
    fstream file;//input output operator
    file.open("intro.dat",ios::in|ios::out|ios::binary);//open file in bin mode
                                                        //for input/output
    
    //Declare intro strings
    int strngSz=30;//size for welcome strings
    char wlcome1[strngSz]= " ";//first welcome string
    char wlcome2[strngSz]= "Welcome to MINESWEEPER!";//second welcome string
    char wlcome3[strngSz]= "";//third welcome string
    
    //Declare enumeration for use in a stupid way for points
    enum stupid{one,two};
    
    //Copy welcome string to 1
    if(one<two){//stupid way to use enumeration
        strcpy(wlcome1,wlcome2);//copy string 2 onto string 1
    }
    
    //write contents of wlcome1 to binary file
    file.write(wlcome1,sizeof(wlcome1));//write contents of wlcome1 to bin file
    file.close();//close file
    
    //read in contents of binary file to string
    file.open("intro.dat",ios::in|ios::out|ios::binary);//reopen file for input
    file.read(wlcome3,sizeof(wlcome3));//read in from file
    //Display instructions
    intro(wlcome3);//display first line of intro
    
    
    
    //Declare Variables and initialize variables for game
    int rows=12;//Two more than necessary for border
    char playAry[rows][COLS];//Grid that player sees and uses
    char **dynAry=initAry(rows);
    Bomb *array2D=filStrc(dynAry,rows);//copy contents of dynamic array to bomb
    bool alive=true;//If player is alive or dead
    int nFlags=0;//counter for number of flags
    int bombFlg=0;//counter for number of flags on bombs
    bool win=false;
    
    //Fill Arrays and print playAry
    initAry(rows);//initialize array to 'b' for border
    fillAry(array2D,playAry);//fill in usable part of array with 'X'
    prntAry(playAry,rows);//Print the array
//    prntAry(array2D); //used for testing to manually compare grids
//    cntBomb(array2D); //used for testing to verify bomb count
    
    //Choose a position and search for bombs
    while(alive&&!win){//checks to see if player is alive and has not won yet
        
        alive=choice(array2D,playAry,rows,nFlags,bombFlg,win);//inputs user's choice and checks for bombs
    }
    
    //Destroy dynamic components
    destroy(array2D);
    
    //Exit stage right!
    return 0;
}
void intro(string welcome){//intro/instructions for game
    cout<<welcome<<endl;
    cout<<"The objective is to flag all of the tiles that "
            <<"contain a bomb"<<endl;
    cout<<"First you will input how many bombs you "
            <<"want to play with [1-99]"<<endl;
    cout<<"Next select a tile"<<endl;
    cout<<"You do this by entering your action, 's' for select, "
            <<"or 'f' for flag"<<endl;
    cout<<"Follow your action with a space and then a number [1-10] "
            <<"for what row you want to select"<<endl;
    cout<<"Followed by another space and a number [1-10] for what "
            <<"column you want"<<endl;
    cout<<"An example input is [s 4 5]"<<endl<<endl<<endl<<endl;
}
char **initAry(int row){
    char **a=new char*[row];
    for(int i=0;i<row;i++){
        a[i]=new char[COLS];
    }
    for(int i=0;i<row;i++){
        for (int j=0;j<COLS;j++){
            a[i][j]='b';//initialize border to 'b'
        }
    }
    return a;//return the array
}
Bomb *filStrc(char **a,int row){
    Bomb *d2=new Bomb;
    d2->rows=row;
    d2->cols=COLS;
    (*d2).bombAry=a;
    return d2;
    
}
void fillAry(Bomb *d2,char playAry[][COLS]){
    for(int row=1;row<d2->rows-1;row++){
        for(int col=1;col<d2->cols-1;col++){
            d2->bombAry[row][col]='X';//Fill in the play area with X's
        }
    }
    copyAry(playAry,d2);//copy bomb grid to player grid
    bombs(d2);//insert bombs onto bomb grid
}
void copyAry(char playAry[][COLS],Bomb *d2){
    for(int i=0;i<d2->rows;i++){
        for(int j=0;j<d2->cols;j++){
            playAry[i][j]=d2->bombAry[i][j];//copy bomb grid to player grid
        }                                   //before bombs are set
    }
}
void prntAry(char playAry[][COLS],int rows){
    cout<<setw(4)<<' ';         //Formatting output
    for(int i=1;i<COLS-1;i++){  
        if(i==10)cout<<' ';     
        cout<<setw(2)<<i;       
    }
    cout<<endl;
    for(int i=0;i<COLS-1;i++){  //Format output
        if(i==0)cout<<setw(2)<<" ";
        cout<<setw(2)<<'-';     
    }
    cout<<endl;
    for(int row=1;row<rows-1;row++){
        cout<<setw(2)<<row;
        cout<<setw(2)<<'|'; //format output
        for(int col=1;col<COLS-1;col++){
             cout<<setw(2)<<playAry[row][col];//output player grid
        }
        cout<<endl;
    }
    cout<<endl;
}
void prntAry(Bomb *d2){//used for testing purposes to print bomb array
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
             cout<<setw(2)<<d2->bombAry[row][col];//output bomb elements
        }
        cout<<endl;
    }
    cout<<endl;
}
bool choice(Bomb *d2,char playAry[][COLS],int rows,int nFlags,int bombFlg,
        bool &win){
    bool live=true;// bool for player's life state
    char action;//which action the player will take [flag/selection]
    int chseRow;//chosen row
    int chseCol;//chosen col
    cin>>action>>chseRow>>chseCol;//input action/row/col
    if(chseRow<1||chseRow>10){//check for valid row input
        cout<<"Invalid row number, ending program"<<endl;
        exit(EXIT_FAILURE);//exit if invalid
    }
    if(chseCol<1||chseCol>10){//check for valid col input
        cout<<"Invalid col number, ending program"<<endl;
        exit(EXIT_FAILURE);//exit if invald
    }
    if(action=='f'){
        nFlags++;//increment flag counter
        if(playAry[chseRow][chseCol]=='F'){//if flagging a flag
            playAry[chseRow][chseCol]='X';//option to unflag by flagging it again thanks mom
            nFlags--;//Decrement since flag was undone
        }
        else playAry[chseRow][chseCol]='F';//set tile to 'F' for flag choice
        if(d2->bombAry[chseRow][chseCol]=='B')bombFlg++;//increment bomb flag counter
    }else if(action=='s'){
        live=check(d2,chseRow,chseCol,playAry);//Select tile and send to check
    }else{//check for invalid action input
        cout<<"Invalid input for action, ending program"<<endl;
        exit(EXIT_FAILURE);//exit if invalid
    }
//    if(live)reveal(a,chseRow,chseCol);
    prntAry(playAry,rows);//print array after choice
    win=victory(d2,nFlags,bombFlg);//check if player has won
    if(win)prntAry(playAry,rows);//print array final time if they won
    return live;//return life state
}
void bombs(Bomb *d2){//used to generate bombs in bomb grid
    cout<<"How many bombs do you want in your game?"<<endl;
    cin>>d2->nBombs;//input number of bombs for game
    for(int bombs=0;bombs<(d2->nBombs);bombs++){//generates bombs until nBombs unique bombs
        int bombRow=rand()%10+1;//chooses random row for bomb
        int bombCol=rand()%10+1;//chooses random col for bomb
        if(d2->bombAry[bombRow][bombCol]=='B'){//tests if bomb already in that spot
            bombs-=1;//if bomb placed on old bomb do generate new one
        }
        d2->bombAry[bombRow][bombCol]='B';//sets bomb position
    }
}
void cntBomb(Bomb *d2){//used for testing to count bombs in bomb grid
    int count=0;//bomb counter
    for(int row=1;row<d2->rows-1;row++){
        for(int col=1;col<d2->cols-1;col++){
            if(d2->bombAry[row][col]=='B'){//search for bombs
                count++;//increment bomb count
            }
        }
    }
    cout<<"There are "<<count<<" bombs"<<endl;//output bombs found
}

//Check function searches for bombs around the chosen tile and sets the tile = to that number
//if no bombs found it sets it to ' '
//if chosen tile is bomb it returns false to set live to false
//after calculations are done it sends the chosen tile to reveal function-
//for further checks
bool check(Bomb *d2,int chceRow,int chceCol,char playAry[][COLS]){
    if(playAry[chceRow][chceCol]!='X')return true;//checks if tile has been checked already
    int bombCnt=0;//how many bombs are around tile
    if(d2->bombAry[chceRow][chceCol]=='B'){//checks if hit bomb
        playAry[chceRow][chceCol]='B';//if so set tile to 'B'
        death();//call death function
        return false;//return false for live bool
    }
    if(d2->bombAry[chceRow-1][chceCol-1]=='B')bombCnt++;//checks top left corner
    if(d2->bombAry[chceRow-1][chceCol]=='B')bombCnt++;//check middle top
    if(d2->bombAry[chceRow-1][chceCol+1]=='B')bombCnt++;//checks top right
    if(d2->bombAry[chceRow][chceCol-1]=='B')bombCnt++;//checks middle left
    if(d2->bombAry[chceRow][chceCol+1]=='B')bombCnt++;//checks middle right
    if(d2->bombAry[chceRow+1][chceCol-1]=='B')bombCnt++;//checks bottom left
    if(d2->bombAry[chceRow+1][chceCol]=='B')bombCnt++;//checks bottom middle
    if(d2->bombAry[chceRow+1][chceCol+1]=='B')bombCnt++;//checks bottom right
    playAry[chceRow][chceCol]=bombCnt+48;//convert bomb count to char
    if(bombCnt==0)playAry[chceRow][chceCol]=' ';//if no bombs set to ' '
    if(playAry[chceRow][chceCol]==' '){//if no bombs near go to reveal function
        reveal(d2,chceRow,chceCol,playAry);
    }
    return true;
}

//The reveal function only serves to resend the surrounding tiles back into the 
//check function
//This is used to reveal an area around the chosen tile if no bombs were found
//nearby
void reveal(Bomb *d2,int chosRow,int chosCol,char playAry[][COLS]){
    if(playAry[chosRow-1][chosCol]!='B'){//checks top middle
        check(d2,chosRow-1,chosCol,playAry);
    }
    if(playAry[chosRow][chosCol-1]!='B'){//checks middle left
        check(d2,chosRow,chosCol-1,playAry);
    }
    if(playAry[chosRow+1][chosCol]!='B'){//checks bottom middle
        check(d2,chosRow+1,chosCol,playAry);
    }
    if(playAry[chosRow][chosCol+1]!='B'){//checks middle right
        check(d2,chosRow,chosCol+1,playAry);
    }
    if(playAry[chosRow-1][chosCol-1]!='B'){//checks top left
        check(d2,chosRow-1,chosCol,playAry);
    }
    if(playAry[chosRow+1][chosCol-1]!='B'){//checks bottom left
        check(d2,chosRow,chosCol-1,playAry);
    }
    if(playAry[chosRow-1][chosCol+1]!='B'){//checks top right
        check(d2,chosRow+1,chosCol,playAry);
    }
    if(playAry[chosRow+1][chosCol+1]!='B'){//checks bottom right
        check(d2,chosRow,chosCol+1,playAry);
    }
}
void death(){//used to output that you died incase user didn't notice
    cout<<"The position you chose had a bomb, you are now dead"<<endl;
}
bool victory(Bomb *d2,int nFlags,int bombFlg){//Used to determine if player won
    if(nFlags==d2->nBombs&&bombFlg==d2->nBombs){
        cout<<"Congratulations you have won"<<endl;
        return true;
    }
    return false;
}
void destroy(Bomb *d2){//delete dynamic elements
    for(int i=0;i<d2->rows;i++){
        delete []d2->bombAry[i];
    }
    delete []d2->bombAry;
    delete d2;
}