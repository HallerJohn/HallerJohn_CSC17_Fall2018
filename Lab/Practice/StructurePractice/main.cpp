/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "MyStruc.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
Bomb *filStrc();
int **fillAry(Bomb *);
void prntStc(Bomb *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    Bomb *point=filStrc();
    point->array=fillAry(point);
    prntStc(point);
    //Initialize Variables
    
    //Process/Map inputs to outputs
    
    //Output data
    
    //Exit stage right!
    return 0;
}
Bomb *filStrc(){
    Bomb *point=new Bomb;
    point->cols=10;
    point->rows=10;
    return point;
}
int **fillAry(Bomb *point){
    int **a=new int*[point->rows];
    for(int i=0;i<point->rows;i++){
        a[i]=new int[point->cols];
    }
    for(int i=0;i<point->rows;i++){
        for(int j=0;j<point->cols;j++){
            a[i][j]=j;
        }
    }
    return a;
}
void prntStc(Bomb *point){
   for(int i=0;i<point->rows;i++){
        for(int j=0;j<point->cols;j++){
            cout<<point->array[i][j];
        }
        cout<<endl;
    }
   cout<<endl;
}