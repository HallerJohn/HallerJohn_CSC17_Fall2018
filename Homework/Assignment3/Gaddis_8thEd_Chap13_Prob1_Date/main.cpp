/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Date.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //class Date object
    Date point;
    
    //Print out info
    point.print1();
    point.print2();
    point.print3();
    //Exit stage right!
    return 0;
}