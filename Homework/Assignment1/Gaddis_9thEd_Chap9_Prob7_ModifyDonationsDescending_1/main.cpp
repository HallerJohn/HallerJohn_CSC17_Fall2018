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
void sortAry(int *,int);
void prntAry(int *,int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int nDonate=20;//number of donations in array
    int *array=fillAry(nDonate);//array of donations
    int perLine=10;//number printed perline
    //Process array
    sortAry(array,nDonate);//sort array
    prntAry(array,nDonate,perLine);//print array
    
    //Clean out the bathroom
    delete []array;
    
    //Exit stage right!
    return 0;
}
int *fillAry(int n){
    int *a=new int[n];
    cout<<"Enter the donations made"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    return a;
}
void sortAry(int *a,int n){
 for(int i=0;i<n-1;i++){
     for(int j=i+1;j<n;j++){
         if(a[j]>a[i]){//This is where i changed it from ascending to descending
             int temp=a[i];
             a[i]=a[j];
             a[j]=temp;
         }
     }
 }   
}
void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}