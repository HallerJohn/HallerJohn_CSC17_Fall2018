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
int *fillAry(int);
void prntAry(int *,int,int);
void sortAry(int *,int);
void findAvg(int *,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare and Initialize Variables
    int size=50;//number of test scores
    int *array=fillAry(size);//fills the array of test scores
    int perLine=10;//number of test score per line
    
    //Sort the original array
    sortAry(array,size);
    //Print sorted array
    prntAry(array,size,perLine);
    //Used to calculate avg test score
    findAvg(array,size);
    
    //Take out the trash
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
void prntAry(int *a,int n,int perLine){
    cout<<endl<<endl<<"Test Scores :"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
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
void findAvg(int *a,int n){
    float avg=0;
    for(int i=0;i<n;i++){
        avg+=a[i];
    }
    avg/=n;
    cout<<endl<<"The average score is :"<<avg<<endl;
}