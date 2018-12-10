/* 
 * File:   PLAYFLD.h
 * Author: John Haller
 *
 * Created on November 20, 2018, 10:09 AM
 */

#include "PLAYFLD.h"
#include "BOMBFLD.h"

#include <iostream>
#include <iomanip>
using namespace std;


Player::Player(){}
//Initializes members inherited from Field class, and drives creation of player field
Player::Player(int nrows,int nCols){
    rows=nrows;
    cols=nCols;
    //Allocates memory for the player field
    makeF();
    //Fills the player field with 'X's
    filFld();
}
//Allocates memory for player field
void Player::makeF(){
    char **a=new char*[rows];
    for(int i = 0;i < rows;i++){
        a[i]=new char[cols];
    }
    field=a;
}

//Fills the player field with 'X's
void Player::filFld(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            field[i][j]='X';
        }
    }
}

//Prints the Player field and its borders
void Player::prtFld(){
    //formatting
    cout<<"    ";
    //Numbers at top of field
    for(int i=0;i<cols;i++){
        cout<<i+1;
        if(i+1<10)cout<<" ";
    }
    //Lines under numbers
    cout<<endl<<"    ";
    for(int i=0;i<cols;i++){
        cout<<"--";
    }
    cout<<endl;
    //Start printing of field
    for(int i = 0; i < rows; i++){
        //Numbers to the left of field as well as a line
        cout<<setw(2)<<i+1<<"| ";
        for(int j = 0; j < cols; j++){
            std::cout<<field[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//Destructor deallocates memory used in player field
Player::~Player(){
    for(int i=0; i<rows;i++){
        delete field[i];
    }
    delete field;
}

