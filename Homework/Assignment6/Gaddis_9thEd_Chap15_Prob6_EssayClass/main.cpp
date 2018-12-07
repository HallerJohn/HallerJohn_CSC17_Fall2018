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
#include "ESSAY.h"
#include "GRADED.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    Essay point;
    
    float temp=point.getCont()+point.getGram()+point.getLen()+point.getSpel();
    point.setScre(temp);
    
    cout<<"The final score is ";
    cout<<point.getScre();
    //Exit stage right!
    return 0;
}