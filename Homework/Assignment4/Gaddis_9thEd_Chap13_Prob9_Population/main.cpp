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
#include "Popu.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int people;
    int died;
    int born;
    //Initialize Variables
    cout<<"Enter the population, number of deaths, and number of births"<<endl;
    cin>>people>>died>>born;
    
    //Validate input
    if(people<0||died<0||born<0){
        cout<<"None of the values can be negative, ending program"<<endl;
        return 0;
    }
    
    //Create population object
    Pop object(people,died,born);
    
    //Output data
    cout<<"The population is : "<<object.getPeop()<<endl;
    cout<<"The death rate is : "<<object.death()<<endl;
    cout<<"The birth rate is : "<<object.birth()<<endl;
    
    //Exit stage right!
    return 0;
}