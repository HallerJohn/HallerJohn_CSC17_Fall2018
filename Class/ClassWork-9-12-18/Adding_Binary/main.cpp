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
string addBin(string, string);

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
    
    //Output data
    cout<<"Your numbers added together = "<<addBin(num1,num2)<<endl;
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
string addBin(string a, string b){
    string answer;//Our final answer
    int carry=0;//var for carry
    int length = a.size();//length of both numbers
    for(int i=1;i<=length||carry==1;i++){//Loop until all digits added or if there is a carry
        int first=a[length-i]-'0';//digit being added for first num
        int second=b[length-i]-'0';//digit being added for second num
        int sum=(first^second^carry)+'0';//if there is 1 or 3 trues it adds "10"
        answer=static_cast<char>(sum)+answer;//add the sum from addition to final answer
        carry=(first&second)|(second&carry)|(first&carry);//if there is 2 '1's then carry is true
    }
    return answer;
}