/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
void fillAry(int *,int);
//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    fstream file;
    string inpFile;
    int SIZE=50;
    int array[SIZE];
    int array2[SIZE];
    //Fill array
    fillAry(array,SIZE);
    //Input the file names
    cout<<"Enter a name for the file for input"<<endl;
    cin>>inpFile;
    inpFile+=".txt";
    
    //Open file
    file.open(inpFile.c_str(), ios::out | ios::in );
    
    for(int i=0;i<SIZE;i++){
        file<<array[i];
    }
    file.close();
    
    file.open(inpFile.c_str());
    
    for(int i=0;i<SIZE;i++){
        file>>array2[i];
    }
    
    cout<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<array2[i];
    }
    //Exit stage right!
    return 0;
}
void fillAry(int *a,int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%50+1;
    }
}