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

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float Cel,      //Celsius
            Fahr;   //Fahrenheit
    //Initialize Variables
    cout<<"Input a temperature in Celsius"<<endl;
    cin>>Cel;
    //Process/Map inputs to outputs
    Fahr=((9*Cel)/5)+32;
    //Output data
    cout<<"That is "<<Fahr<<" degrees in Fahrenheit"<<endl;
    //Exit stage right!
    return 0;
}