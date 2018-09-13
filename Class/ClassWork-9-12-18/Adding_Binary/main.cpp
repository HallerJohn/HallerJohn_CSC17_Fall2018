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
int length(string &,string &);

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    string num1;
    string num2;
    string answer;
    int size=length(num1,num2);
    int carry=0;
    
    //Initialize Variables
    cout<<"input 2 binary numbers"<<endl;
    cin>>num1>>num2;
    
    //Process/Map inputs to outputs
    for(int i=0;i<size+1;i++){
        int digit1= num1.at(i)-'0';
        int digit2= num2.at(i)-'0';
        int sum = (digit1 ^ digit2 ^ carry)+'0';
        answer= (char)sum+answer;
        carry=(digit1 & digit2) | (digit2 & carry) | (digit1 & carry);
    }
    if(carry){
        answer+='1';
    }
    //Output data
    cout<<"The answer is ="<<answer<<endl;
    //Exit stage right!
    return 0;
}

int length( string &num1, string &num2){
    int length1=num1.size();
    int length2=num2.size();
    if(length1>length2){
        for(int i=0;i<length1-length2;i++){
            num1='0'+num1;
        }
        return length2;
    }else if(length2>length1){
        for(int i=0;i<length2-length1;i++){
            num2='0'+num2;
        }
    }return length1;
}