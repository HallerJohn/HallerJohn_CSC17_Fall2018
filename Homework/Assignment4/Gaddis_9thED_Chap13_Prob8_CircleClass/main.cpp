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
#include "Circle.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float r=0;
    //Initialize Variables
    cout<<"Input radius of circle"<<endl;
    cin>>r;
    if(r<0){
        cout<<"Radius cannot be negative.";
        return 0;
    }
    //create circle object
    Circle object(r);
    
    //Output data
    cout<<"Radius        = "<<r<<endl;
    cout<<"Area          = "<<object.getArea()<<endl;
    cout<<"Diameter      = "<<object.getDiam()<<endl;
    cout<<"Circumference = "<<object.getCirc()<<endl;
    
    //Exit stage right!
    return 0;
}