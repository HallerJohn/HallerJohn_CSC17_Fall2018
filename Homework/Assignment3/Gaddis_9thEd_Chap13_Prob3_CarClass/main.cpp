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
#include "Car.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int year;
    string Make;
    
    //input year and Make
    cout<<"Input the year of the car"<<endl;
    cin>>year;
    cin.ignore();
    cout<<"Input the make of the car"<<endl;
    getline(cin,Make);
    
    //Create class object
    Car point(year,Make);
    
    //Accelerate 5 times
    for(int i=0;i<5;i++){
        point.acclrte();
        cout<<"Current speed :"<<point.getSped()<<endl;
    }
    //Brake five times
    for(int i=0;i<5;i++){
        point.brake();
        cout<<"Current speed :"<<point.getSped()<<endl;
    }
    
    //Process/Map inputs to outputs
    
    //Output data
    
    //Exit stage right!
    return 0;
}