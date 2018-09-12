/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
int *fillAry(int,int);
void prntAry(int *,int,int);
void swap(int &,int &);
void smlLst(int *,int,int);
void mrkSort(int *,int);
void shuffle(int *,int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    int size=100;
    int mod=10;
    int *array=fillAry(size,mod);
    
    //Print resulting array
    prntAry(array,size,mod);
    
    
    //Shuffle the array
    shuffle(array,size,7);
    
    //Print shuffled array
    prntAry(array,size,mod);
    
    //Sort the array
    mrkSort(array,size);
    
    //Output data
    prntAry(array,size,mod);
    
    //Clean memory
    delete []array;
    
    //Exit stage right!
    return 0;
}
int *fillAry(int n,int m){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=i%m;
    }
    return array;
}
void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
void swap(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}
void smlLst(int *a,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i])swap(a[pos],a[i]);
    }
}
void mrkSort(int *a,int n){
    for(int i=0;i<n-1;i++){
        smlLst(a,n,i);
    }
}
void shuffle(int *a,int n,int nShuf){
    for(int shuf=1;shuf<nShuf;shuf++){
        for(int i=0;i<n;i++){
            int temp=rand()%n;
            if(i!=temp)swap(a[i],a[temp]);
        }
    }
}