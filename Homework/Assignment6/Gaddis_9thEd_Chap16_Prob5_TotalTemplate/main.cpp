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
#include "TOTAL.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int intCnt=0;
    float fltCnt=0;
    
    //Input ints and output total
    cout<<"How many integers would you like to sum?"<<endl;
    cin>>intCnt;
    cout<<"Now enter your integers"<<endl;
    cout<<"The total of your integers is = "<<total(intCnt)<<endl;
    
    //Input floats and output total
    cout<<"How many floats would you like to sum?"<<endl;
    cin>>fltCnt;
    cout<<"Now enter your floats"<<endl;
    cout<<"The total of your floats is = "<<total(fltCnt)<<endl;
    
    
    
    //Output data
    
    //Exit stage right!
    return 0;
}