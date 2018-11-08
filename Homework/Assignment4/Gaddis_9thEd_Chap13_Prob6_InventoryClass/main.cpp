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
#include "Invntry.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variable
    int itmNum;
    int itmQnt;
    float itmCost;
    //Initialize
    cout<<"Enter the item number"<<endl;
    cin>>itmNum;
    cout<<"Enter the quantity of item"<<endl;
    cin>>itmQnt;
    cout<<"Enter the cost of the item"<<endl;
    cin>>itmCost;
    //Validate input
    if(itmNum<0||itmQnt<0||itmCost<0){
        cout<<"Cannot have negative value, exiting program"<<endl;
        return 0;
    }
    //Create class object with constructor
    Invntry object(itmNum,itmQnt,itmCost);

    //Output data
    cout<<"Item number  : "<<object.getINum()<<endl;
    cout<<"Item Cost    : $"<<object.getCost()<<endl;
    cout<<"Item Quantity: "<<object.getqnt()<<endl;
    cout<<"Total cost   : "<<object.getTotC()<<endl;
    
    //Exit stage right!
    return 0;
}