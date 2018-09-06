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

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int month;            //month of year
    int year;             //year
    bool Dumb;      //did they mess up
    //Initialize Variables
    do{
        Dumb=false;
        cout<<"Input a month of the year [1-12]"<<endl;
        cin>>month;
        cout<<"Now input a year"<<endl;
        cin>>year;
        if(month<1||month>12){
            Dumb=true;
            cout<<"Please input an actual month"<<endl;
        }
    }while(Dumb);
    //Process/Map inputs to outputs
    if(month==2){
        if(year%100==0){
            if(year%400==0){
                cout<<"There are 29 days in this month"<<endl;
            }
        }else if(year%4==0){
            cout<<"There are 29 days in this month"<<endl;
        }else{
            cout<<"There are 28 days in this month"<<endl;
        }
    }
    switch(month){
        case 1:{
            cout<<"There are 31 days in this month"<<endl;break;
        }case2:{
            break;
        }case 3:{
            cout<<"There are 31 days in this month"<<endl;break;
        }case 4:{
            cout<<"There are 30 days in this month"<<endl;break;
        }case 5:{
            cout<<"There are 31 days in this month"<<endl;break;
        }case 6:{
            cout<<"There are 30 days in this month"<<endl;break;
        }case 7:{
            cout<<"There are 31 days in this month"<<endl;break;
        }case 8:{
            cout<<"There are 31 days in this month"<<endl;break;
        }case 9:{
            cout<<"There are 30 days in this month"<<endl;break;
        }case 10:{
            cout<<"There are 31 days in this month"<<endl;break;
        }case 11:{
            cout<<"There are 30 days in this month"<<endl;break;
        }case 12:{
            cout<<"There are 31 days in this month"<<endl;break;
        }
    }
    //Output data
    
    //Exit stage right!
    return 0;
}