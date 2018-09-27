/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//User Libraries
#include "SalesData.h"
//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    ofstream out;
    SalesDt sdata;
    
    //Open output file
    out.open("SalesData.txt");
    //Initialize Variables
    cout<<"Input the division name, the quarter, and the sales for that quarter"
            <<endl;
    cin>>sdata.dvision>>sdata.quarter>>sdata.data;
    //Validate input
    if(sdata.data<0){
        cout<<"Sales data cannot be negative"<<endl;
        return 0;
    }
    
    //Output data
    out<<sdata.dvision<<"\r\n";
    out<<sdata.quarter<<"\r\n";
    out<<sdata.data<<"\r\n";
    
    
    //Close file
    out.close();
    //Exit stage right!
    return 0;
}