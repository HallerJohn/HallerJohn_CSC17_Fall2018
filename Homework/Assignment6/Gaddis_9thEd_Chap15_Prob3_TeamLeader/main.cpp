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
#include "LEADER.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void print(Leader);

//Execution Begins Here
int main(int argc, char** argv) {
    //create production worker object
    Leader point;
    
    //set shift
    cout<<"Enter Monthly bonus"<<endl;
    point.setBns();
    
    //set pay rate
    cout<<"Enter Hours required"<<endl;
    point.setReq();
    
    //Set hours done
    cout<<"Enter hours completed"<<endl;
    point.setDone();
            
    //print data
    print(point);
    
    //Exit stage right!
    return 0;
}

void print(Leader point){
    cout<<point.getName()<<endl;
    cout<<point.getNumb()<<endl;
    cout<<point.getDate()<<endl;
    cout<<point.getBns()<<endl;
    cout<<point.getReq()<<endl;
    cout<<point.getDone()<<endl;
}