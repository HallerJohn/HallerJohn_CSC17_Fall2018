/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void encrypt(char [],int);
void decrypt(char [],int);
void swap(char,char);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice=' ';
    int size=4;
    char data[size];
    //Initialize Variables
    cout<<"Input the data"<<endl;
    cin>>data;
    for(int i=0;i<size;i++){
        if(data[i]-48<0||data[i]-48>7){
            cout<<"Incorrect number input, exiting program"<<endl;
            exit(EXIT_FAILURE);
        }
    }
    
    cout<<"Would you like to encrypt [e], or decrypt [d]?"<<endl;
    cin>>choice;
    if(choice=='e')encrypt(data,size);
    else decrypt(data,size);
    //Process/Map inputs to outputs
    
    //Output data
    
    //Exit stage right!
    return 0;
}
void encrypt(char data[],int size){
    int digit[size];
    for(int i=0;i<size;i++){
        digit[i]=(data[i]-48+5)%8;
    }
    data[0]=digit[2]+48;
    data[2]=digit[0]+48;
    data[1]=digit[3]+48;
    data[3]=digit[1]+48;
    
    cout<<"The encoded data is :";
    for(int i=0;i<size;i++){
        cout<<data[i];
    }
}
void decrypt(char data[],int size){
    int digit[size];
    for(int i=0;i<size;i++){
        digit[i]=(data[i]-48-5+8)%8;
    }
    data[0]=digit[2]+48;
    data[2]=digit[0]+48;
    data[1]=digit[3]+48;
    data[3]=digit[1]+48;
    
    cout<<"The encoded data is :";
    for(int i=0;i<size;i++){
        cout<<data[i];
    }
}