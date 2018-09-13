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
#include <vector>
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
int numMode(int *,int);
int nModes(int *,int,int);
vector<int> fndMode(int *,int,int,vector<int> &modeVal);
float fndMean(int *,int);
int findMed(int *,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    vector<int> modeVal;
    int size=100;
    int mod=10;
    int *array=fillAry(size,mod);
    
    //Print resulting array
//    prntAry(array,size,mod);
    
    
    //Shuffle the array
    shuffle(array,size,7);
    
    //Print shuffled array
//    prntAry(array,size,mod);
    
    //Sort the array
    mrkSort(array,size);
    
    //Output data
    prntAry(array,size,mod);
    
    //find mean
    cout<<"The mean is ="<<fndMean(array,size)<<endl;
    //find median
    cout<<"The median is "<<findMed(array,size)<<endl;
    
    //Find the highest mode and the number of modes
    int mode=numMode(array,size);
    int modes=nModes(array,size,mode);
    
    //print results
    cout<<endl<<"The highest mode is "<<mode<<endl;
    cout<<endl<<"There are "<<modes<<" modes"<<endl;
    
    //find the value of modes
    fndMode(array,size,mode,modeVal);
    
    //print results
    if(modes>0){
        cout<<endl<<"The Mode(s) are :"<<endl;
        for(int i=0;i<modes;i++){
            cout<<modeVal[i]<<endl;
        }
    }
    
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

int numMode(int *a,int n){
    int fnCount=0;//Final count for mode
    int crCount=1;//Current count for mode
    for(int i=0;i<n;i++){
        if((a[i]-a[i+1])==0){
            crCount++;
        }else{
            crCount=0;
        }if(crCount>fnCount){
            fnCount=crCount;
        }
          
    }
    return fnCount;
}

int nModes(int *a,int n,int m){
    int nMode=0;//Final number of modes
    int crCount=1;//Current count for mode
    for(int i=0;i<n;i++){
        if((a[i]-a[i+1])==0){
            crCount++;
        }else{
            crCount=1;
        }if(crCount==m){
            nMode++;
        }
          
    }
    return nMode;
}

vector<int> fndMode(int *a,int n,int m,vector<int> &modeVal){
    int Mode=0;//What the mode is
    int crCount=1;//Current count for mode
    for(int i=0;i<n;i++){
        if((a[i]-a[i+1])==0){
            crCount++;
        }else{
            crCount=1;
        }if(crCount==m){
            modeVal. push_back(a[i]);
        }
          
    }
    return modeVal;
}

float fndMean(int *a,int n){
    float mean=0;
    for(int i=0;i<n;i++){
        mean+=a[i];
    }
    return mean/n;
}

int findMed(int *a,int n){
    if(n%2==0){
        return (a[(n+1)/2]+a[n/2])/2;
    }else return a[n+1/2];
}