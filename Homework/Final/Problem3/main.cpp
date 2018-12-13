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

#include "Prob3TableInh.h"

#define C_TEXT( text ) ((char*)std::string( text ).c_str());
//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
//    char * s = C_TEXT(  );
    string s = "Problem3.txt";
    Prob3TableInherited<int> tab(s.c_str(),rows,cols);
    const int *naugT=tab.getTable();
    cout<<"Input Table: "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Augmented Table"<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
    
    //Exit stage right!
    return 0;
}