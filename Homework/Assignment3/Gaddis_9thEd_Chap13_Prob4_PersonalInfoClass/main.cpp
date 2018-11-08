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
#include "PerInfo.h"

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
        cout<<"Enter info for person #"<<i+1<<endl;
        person[i].setName();
        person[i].setAddr();
        person[i].setAge();
        person[i].setPhne();
    }
    //Output Data
    for(int i=0;i<SIZE;i++){
        cout<<"Name: "<<person[i].getName()<<endl;
        cout<<"Address: "<<person[i].getAddr()<<endl;
        cout<<"Age: "<<person[i].getAge()<<endl;
        cout<<"Phone #: "<<person[i].getPhne()<<endl;
    }
    //Exit stage right!
    return 0;
}