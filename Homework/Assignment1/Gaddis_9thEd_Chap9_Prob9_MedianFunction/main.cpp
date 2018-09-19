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
int *fillAry(int);
void sortAry(int *,int);
void prntAry(int *,int,int);
float findMed(int *,int);

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    int size=50;
    int *array=fillAry(size);
    int perLine=10;
    
    //Sort array
    sortAry(array,size);
    prntAry(array,size,perLine);
    //Initialize Variables
    
    //Process/Map inputs to outputs
    
    //Output data
    cout<<"The median ="<<findMed(array,size)<<endl;
    
    //Teach old man joe a lesson
    delete []array;
    
    //Exit stage right!
    return 0;
}
int *fillAry(int n){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%100+1;
    }
    return a;
}
void sortAry(int *a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
float findMed(int *a,int n){
    if(n%2==0){
        return (a[n/2]+a[n/2-1])/2;
    }else return a[n+1/2];
}
void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}