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
#include "PRDCWRK.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void print(PrdcWrk);

//Execution Begins Here
int main(int argc, char** argv) {
    //create production worker object
    PrdcWrk point;
    
    //set shift
    cout<<"Enter which shift day[1] or night[2]"<<endl;
    point.setShft();
    
    //set pay rate
    cout<<"Enter pay rate"<<endl;
    point.setRate();
            
    //print data
    print(point);
    
    //Exit stage right!
    return 0;
}

void print(PrdcWrk point){
    cout<<point.getName()<<endl;
    cout<<point.getNumb()<<endl;
    cout<<point.getDate()<<endl;
    cout<<point.getShft()<<endl;
    cout<<point.getRate()<<endl;
}