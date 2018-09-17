/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
void length(string &,string &);

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    string num1;
    string num2;
    
    //Initialize Variables
    cout<<"input 2 binary numbers"<<endl;
    cin>>num1>>num2;
    
    //Make them equal length
    length(num1,num2);
    cout<<"Number 1 = "<<num1<<endl<<"Number 2 = "<<num2<<endl;
    //Process/Map inputs to outputs
    
    //Output data
    
    //Exit stage right!
    return 0;
}

void length( string &num1, string &num2){
    int length1=num1.size();
    int length2=num2.size();
    if(length1>length2){
        for(int i=0;i<length1-length2;i++){
            num2='0'+num2;
        }
    }else if(length2>length1){
        for(int i=0;i<length2-length1;i++){
            num1='0'+num1;
        }
    }
}