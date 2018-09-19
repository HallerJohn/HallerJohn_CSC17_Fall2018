/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
int *fillAry(int);
int *rvrsAry(int *,int);
void prntAry(int *,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int size=10;
    int *array=fillAry(size);
    prntAry(array,size);
    int *reverse=rvrsAry(array,size);
    prntAry(reverse,size);
    //Initialize Variables
    
    //Process/Map inputs to outputs
    
    //Throw a party
    delete []reverse;
    delete []array;
    
    //Exit stage right!
    return 0;
}
int *fillAry(int n){
    int *a=new int[n];
    for(int i=0;i<10;i++){
        a[i]=i+1;
    }
    return a;
}
int *rvrsAry(int *a,int n){
    int *reverse=new int[n];
    for(int i=0;i<n;i++){
        reverse[i]=a[n-1-i];
    }
    return reverse;
}
void prntAry(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}