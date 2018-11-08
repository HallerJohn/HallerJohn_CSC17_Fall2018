/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "EmpInfo.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int SIZE=3;
    INFO *person=new INFO[SIZE];
    
    //Fill in personal info
    for(int i=0;i<SIZE;i++){
        cout<<"Enter info for employee #"<<i+1<<endl;
        person[i].setName();
        person[i].setID();
        person[i].setDept();
        person[i].setPos();
    }
    //Output Data
    for(int i=0;i<SIZE;i++){
        cout<<"Name: "<<person[i].getName()<<endl;
        cout<<"ID Number: "<<person[i].getID()<<endl;
        cout<<"Department: "<<person[i].getDept()<<endl;
        cout<<"Title: "<<person[i].getPos()<<endl;
    }
    
    delete person;
    //Exit stage right!
    return 0;
}