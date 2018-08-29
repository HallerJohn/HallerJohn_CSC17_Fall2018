/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Compare ints to floats
 */

//System Libraries
#include <iostream>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned char cx=0xDB;//width of 8 binary point bp 4 13.7
    unsigned char cy=0b00100000;//width of 6 bits no bp 32
    unsigned short cRes;
    
    //Process/Map inputs to outputs
    cRes=cx*cy;//wd 14 bp 4
    cRes>>=4;//wd 10 bp 0
    
    //Output data
    cout<<static_cast<int>(cx)<<" Shifted Binary = 13.7 = /16"<<endl;
    cout<<static_cast<int>(cy)<<" Regular interger"<<endl;
    cout<<cRes<<endl;
    cout<<13.7*32<<endl;
    //Test how much faster integer math is to floating point
    int itest;
    float jf,kf,ftest;
    int beg=static_cast<int>(time(0));
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            for(int k=1;k<=100000;k++){
                jf=j;
                kf=k;
//                itest=j*k;
//                ft         est=jf*kf;
            }
        }
    }
    int end=static_cast<int>(time(0));
    cout<<"Total time = "<<end-beg<<endl;
    
    
    //Exit stage right!
    return 0;
}