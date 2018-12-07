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
#include "ABSVAL.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare ints
    int posNumb=5;
    int negNumb=-6;
    cout<<"The absolute value of "<<posNumb<<" is = "<<absVal(posNumb)<<endl;
    cout<<"The absolute value of "<<negNumb<<" is = "<<absVal(negNumb)<<endl;
    
    //Declare ints
    float psFloat=10.5;
    float ngFloat=-21.87;
    cout<<"The absolute value of "<<psFloat<<" is = "<<absVal(psFloat)<<endl;
    cout<<"The absolute value of "<<ngFloat<<" is = "<<absVal(ngFloat)<<endl;
    
    //Exit stage right!
    return 0;
}