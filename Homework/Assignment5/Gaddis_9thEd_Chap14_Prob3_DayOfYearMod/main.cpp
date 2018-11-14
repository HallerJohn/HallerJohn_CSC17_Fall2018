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
#include "DAYYEAR.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int day;
    string month;
    
    //Input day to convert
    cout<<"Input the day of the month"<<endl;
    cin>>day;
    if(day<1||day>365){
        cout<<"Invalid number";
        return 0;
    }
    cout<<"Input the month"<<endl;
    cin>>month;
    //Create the object
    DayYear object(day,month);
    DayYear object2=++object;
    //Exit stage right!
    return 0;
}