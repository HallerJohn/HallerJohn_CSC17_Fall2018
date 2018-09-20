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
    ifstream in;//file input
    ofstream out;//file output
    string scdFile;//input file
    string sntence;//string being input
    
    //Initialize Variables
    cin>>scdFile;//input the second file name
    
    //input and output files
    in.open("FirstFile.txt");
    scdFile+=".txt";
    out.open(scdFile.c_str());
    //Process/Map inputs to outputs
    if(in.is_open()){
        while(getline(in,sntence)){
            in>>sntence;
        }
    }
    for(int i=1;i<sntence.length();i++){
        if(sntence[0]>=97)sntence[0]-=32;
        if(sntence[i]<97&&sntence[i]!=' ')sntence[i]+=32;
    }
    //Output data
    out<<sntence;
    
    //close the file
    in.close();
    //Exit stage right!
    return 0;
}