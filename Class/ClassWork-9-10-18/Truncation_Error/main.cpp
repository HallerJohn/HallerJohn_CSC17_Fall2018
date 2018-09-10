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
    float frac=0.1;
    float sum=0.0;
    int nLoops=10000000;
    
    
    //Process/Map inputs to outputs
    for(int loop=1;loop<=nLoops;loop++){
        sum+=frac;
    }
    
    //Output data
    cout<<"The answer should be ="<<frac<<"*"<<nLoops<<"="<<frac*nLoops<<endl;
    cout<<"Actual answer ="<<sum<<endl;
    cout<<"Error ="<<(1-sum/frac/nLoops)*100<<"%"<<endl;
    
    //Exit stage right!
    return 0;
}