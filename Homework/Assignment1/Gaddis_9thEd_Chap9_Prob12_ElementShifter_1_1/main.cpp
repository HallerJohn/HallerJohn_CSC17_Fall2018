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
int *newArry(int *,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables and initialize
    int size=10;
    int array[size]={1,2,3,4,5,6,7,8,9,10};
    //create and Initialize new array
    int *array2=newArry(array,size+1);
    //Print the shifted array
    for(int i=0;i<size+1;i++){
        cout<<array2[i]<<" ";
    }
    cout<<endl;
        
    //Take out the trash
    delete []array2;
    //Exit stage right!
    return 0;
}
int *newArry(int *a,int n){
    int *array2=new int[n];
    for(int i=0;i<n-1;i++){
        array2[i+1]=a[i];
    }
    return array2;
}