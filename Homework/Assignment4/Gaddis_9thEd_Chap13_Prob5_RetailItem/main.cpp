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
#include "RetailItem.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare the objects
    Invntry one("Jacket",12,59.95);
    Invntry two("Designer Jeans",40,34.95);
    Invntry three("Shirt",20,24.95);
    
    //output contents of first object
    cout<<one.getDesc()<<" ";
    cout<<one.getUnit()<<" ";
    cout<<"$"<<one.getPrce()<<endl;
    //output contents of second object
    cout<<two.getDesc()<<" ";
    cout<<two.getUnit()<<" ";
    cout<<"$"<<two.getPrce()<<endl;
    //output contents of third object
    cout<<three.getDesc()<<" ";
    cout<<three.getUnit()<<" ";
    cout<<"$"<<three.getPrce()<<endl;
    
    
    //Exit stage right!
    return 0;
}