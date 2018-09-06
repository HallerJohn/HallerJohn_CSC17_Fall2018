/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
const float YenPrDo=110.81;
const float EurPrDo=0.86;

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float Dollar,       //Dollars
            Euro,       //Euros
            Yen;        //Yen
    //Initialize Variables
    cout<<"Input an amount of money in US Dollars"<<endl;
    cin>>Dollar;
    //Process/Map inputs to outputs
    Yen=Dollar*YenPrDo;
    Euro=Dollar*EurPrDo;
    
    //Output data
    cout<<fixed<<showpoint;
    cout<<"That is = "<<setprecision(2)<<setw(10)<<Yen<<" Yen"<<endl;
    cout<<"That is = "<<setprecision(2)<<setw(10)<<Euro<<" Euros"<<endl;
    //Exit stage right!
    return 0;
}