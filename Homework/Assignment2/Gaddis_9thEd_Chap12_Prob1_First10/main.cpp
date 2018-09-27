/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    ifstream in;
    string lines;
    //Initialize Variables
    in.open("inFile.txt");
    for(int i=0;i<10;i++){
        getline(in,lines);
        cout<<lines<<endl;
    }
    //Process/Map inputs to outputs
    lines={" "};
    getline(in,lines);
    if(lines!=" "){
        cout<<"Only first ten lines displayed"<<endl;
    }else{
        cout<<"The entire file has been displayed"<<endl;
    }
    //Output data
    
    //Close the file
    in.close();
    //Exit stage right!
    return 0;
}