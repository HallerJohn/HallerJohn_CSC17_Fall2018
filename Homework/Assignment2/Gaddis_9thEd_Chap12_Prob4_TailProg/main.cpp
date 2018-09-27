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
    char charact;
    int endCnt=-1;
    //Initialize Variables
    in.open("inFile.txt");
    do{
        getline(in,lines);
        endCnt++;
    }while(!in.eof());
    in.close();
    in.open("inFile.txt");
    //Process/Map inputs to outputs
    int n=endCnt-10;
    if(n>0){
        for(int i=0;i<n;i++){
            getline(in,lines);
        }
    }
    for(int i=0;i<10;i++){
        getline(in,lines);
        cout<<lines<<endl;
    }
    if(n<=0){
        cout<<"The whole file has been displayed"<<endl;
    }
    //Output data
    
    //Close the file
    in.close();
    //Exit stage right!
    return 0;
}