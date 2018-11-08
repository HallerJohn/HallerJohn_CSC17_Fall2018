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
#include "TstScre.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int SIZE=3;
    float tests[SIZE];
    //Initialize Variables
    cout<<"Enter your test scores"<<endl;
    for(int i=0;i<SIZE;i++){
        cin>>tests[i];
    }
    //Create class object
    TstScre object(tests);
    
    //Calc avg
    object.setAvgS();
    
    //Output data
    for(int i=0;i<SIZE;i++){
        cout<<"Score "<<i<<" = "<<object.getScre(i)<<endl;
    }
    cout<<"Average score = "<<object.getAvgS()<<endl;
    
    //Cleanup
    object.cleanup();
    //Exit stage right!
    return 0;
}