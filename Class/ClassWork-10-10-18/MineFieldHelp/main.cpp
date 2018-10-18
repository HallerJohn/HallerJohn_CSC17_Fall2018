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

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    int rows=100;
    int cols=100;
    char array[rows][cols];
    //Initialize Variables
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            array[i][j]='X';
        }
    }
    cout<<endl<<endl<<endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            array[i+50][j+50]=' ';
        }
    }
    int bombs=0;
    for(int i=0;i<10,bombs<10;i++){
        int newRow=rand()%10+50;
        int newCol=rand()%10+50;
        if(array[newRow][newCol]==' ')bombs++;
        array[newRow][newCol]='B';        
    }
    //Process/Map inputs to outputs
    for(int i=49;i<61;i++){
        for(int j=49;j<61;j++){
            cout<<array[i][j];
        }
        cout<<endl;
    }
    //Output data
    
    //Exit stage right!
    return 0;
}