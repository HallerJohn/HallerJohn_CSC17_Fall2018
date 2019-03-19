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
#include "Prob2Sort.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    Prob2Sort<char> rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*15];
    char *ch2p=ch2;
    int cnt=0;
    while(infile.get(*ch2)){
        cout<<*ch2;ch2++;
        cnt++;
        if(cnt%15==0) cout<<endl;
    }
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc=rc.sortArray(ch2p,10,15,column,ascending);
    for(int i=0;i<10;i++){
        for(int j=0;j<15;j++){
            cout<<zc[i*15+j];
        }
        cout<<endl;
    }
    delete []zc;
    cout<<endl;
    return 0;
}