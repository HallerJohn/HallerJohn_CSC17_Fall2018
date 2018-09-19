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
int *makeAry(int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int size=10;
    int *array=makeAry(size);
    
    //Initialize Variables
    
    //Process/Map inputs to outputs
    
    //Talk to a man about a horse
    delete []array;
    
    
    //Exit stage right!
    return 0;
}
int *makeAry(int n){
    int *a=new int[n];
    return a;
}