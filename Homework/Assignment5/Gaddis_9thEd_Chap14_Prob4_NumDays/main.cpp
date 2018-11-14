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
#include "NUMDAYS.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int hours;
    
    //Initialize Variables
    cout<<"Input hours worked for object 1"<<endl;
    cin>>hours;
    
    //create object for class
    NumDays object1(hours);
    
    //Initialize Variables
    cout<<"Input hours worked for object 2"<<endl;
    cin>>hours;
    
    //create object for class
//    NumDays object2(hours);
    
    //Output data
    object1.print();
//    object2.print();
    
    //Add the two objects
//    cout<<object1+object2;
    //Exit stage right!
    return 0;
}