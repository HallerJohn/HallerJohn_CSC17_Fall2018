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
#include "EMPLOYEE.h"
#include "SPRVSR.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void print(Sprvsr);

//Execution Begins Here
int main(int argc, char** argv) {
    //create production worker object
    Sprvsr point;
    
    //set shift
    cout<<"Enter yearly salary"<<endl;
    point.setSlry();
    
    //set pay rate
    cout<<"Enter bonus earned"<<endl;
    point.setBns();
            
    //print data
    print(point);
    
    //Exit stage right!
    return 0;
}

void print(Sprvsr point){
    cout<<point.getName()<<endl;
    cout<<point.getNumb()<<endl;
    cout<<point.getDate()<<endl;
    cout<<point.getSlry()<<endl;
    cout<<point.getBns()<<endl;
}