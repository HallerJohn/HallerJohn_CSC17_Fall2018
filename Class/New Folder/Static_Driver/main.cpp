/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
const int COL=100;

//Function Prototypes
void fill1d(int [],int);
void fill2d(int [][COL]int);
int * fill1d(int);
int ** fill2d(int,int);
void prnt1d(int *,int,int);
void prnt2d(int **,int,int);


//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int ROW=5;
    int s1dAry[ROW][COL];
    int s2dAry[ROW][COL];
    int *d1dAry=fill1d(ROW*COL);
    int **d2dAry=fill2d(ROW,COL);
    
    //Initialize Variables
    fill1d(s1dAry,ROW*COL);
    fill2d(s2dAry,ROW);
    
    //Output data
    prnt1d(s1dAry,ROW*COL,COL);
    prnt1d(d1dAry,ROW*COL,COL);
    prnt2d(s2dAry,ROW,COL);
    prnt2d(d2dAry,ROW,COL);
    
    //Deallocate memory
    delete []d1dary
    //Exit stage right!
    return 0;
}

void fill1d(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}
void fill2d(int a[][COL]int row){
    for(int i=row;i<row;i++){
        for(int j=0;j<COL;j++){
            a[i][j]=rand()%90+10;
        }
    }
}
int * fill1d(int n){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}
int ** fill2d(int row,int COL){
    int
    for(int i=row;i<n;i++){
        for(int j=0;j<COL;j++){
            a[i][j]=rand()%90+10;
        }
    }
}
void prnt1d(int *,int,int);
void prnt2d(int **,int,int);