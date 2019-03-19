/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "PROB1.h"
#include "Prob2Sort.h"
#include "Prob3Table.h"
#include "Prob3TableInh.h"
#include "SavingsAccount.h"
#include "Employee.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
//Execution Begins Here
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    bool repeat=true;
    
    
    do{
        cout<<"Enter 1 to go to Problem 1"<<endl;
        cout<<"Enter 2 to go to Problem 2"<<endl;
        cout<<"Enter 3 to go to Problem 3"<<endl;
        cout<<"Enter 4 to go to Problem 4"<<endl;
        cout<<"Enter 5 to go to Problem 5"<<endl;
        cout<<"Enter 6 to go to Problem 6"<<endl;
        cout<<"Enter any other number to end program"<<endl;
        
        char choice;
        cin>>choice;
        
        switch(choice){
            case '1':{
                cout<<endl<<endl;
                problem1();
                cout<<endl<<endl;
                break;
            }case '2':{
                cout<<endl<<endl;
                problem2();
                cout<<endl<<endl;
                break;
            }case '3':{
                cout<<endl<<endl;
                problem3();
                cout<<endl<<endl;
                break;
            }case '4':{
                cout<<endl<<endl;
                problem4();
                cout<<endl<<endl;
                break;
            }case '5':{
                cout<<endl<<endl;
                problem5();
                cout<<endl<<endl;
                break;
            }case '6':{
                cout<<endl<<endl;
                problem6();
                cout<<endl<<endl;
                break;
            }default:{
                cout<<"Ending program."<<endl;
                repeat=false;
            }
        }
    }while(repeat);
    
    //Exit stage right!
    return 0;
}

void problem1(){
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    char n=5;
    char rndseq[]={18,33,56,79,125};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    for(int i=1;i<=ntimes;i++)
    {
            a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
            cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}
void problem2(){
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
}
void problem3(){
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
//    char * s = C_TEXT(  );
    string s = "Problem3.txt";
    Prob3TableInherited<int> tab(s.c_str(),rows,cols);
    const int *naugT=tab.getTable();
    cout<<"Input Table: "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Augmented Table"<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
}
void problem4(){
    srand(static_cast<unsigned int>(time(0)));
    float x=rand()&1000-500;
    SavingsAccount mine(x);
    for(int i=1;i<=10;i++)
    {
            mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
            <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
            <<mine.TotalRecursive((float)(0.10),7)
            <<" Recursive Calculation "<<endl;
}
void problem5(){
    Employee Mary("Mary","VP",50.0);
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(60));
    Mary.toString();
}
void problem6(){
    cout<<"Problem 6 will be in a picture contained in the final folder"<<endl;
}