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
#include "MIN.h"
#include "MAX.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Using integers
    int int1=5;
    int int2=10;
    cout<<"The minimum integer is "<<getMin(int1,int2)<<endl;
    cout<<"The maximum integer is "<<getMax(int1,int2)<<endl;
    
    //Using floats
    float float1=10.5;
    float float2=22.86;
    cout<<"The minimum float is "<<getMin(float1,float2)<<endl;
    cout<<"The maximum float is "<<getMax(float1,float2)<<endl;
    
    //Using chars
    char char1='h';
    char char2='a';
    cout<<"The minimum char is '"<<getMin(char1,char2)<<"'"<<endl;
    cout<<"The maximum char is '"<<getMax(char1,char2)<<"'"<<endl;
    
    //Exit stage right!
    return 0;
}