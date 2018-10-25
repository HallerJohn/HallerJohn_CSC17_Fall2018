/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries
#include "CustAct.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
Account *flStruc();//fill contents of structure and return pointer to it
float calcBal(Account *);//calculate balance
void ptStruc(Account *);//print contents of structure
void cleanUp(Account *);//Cleanup

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    Account *point=flStruc();//pointer to structure
    
    //Initialize Variables
    
    //Process/Map inputs to outputs
    point->endBal=calcBal(point);//Calculate final balance
    
    //Output data
    ptStruc(point);//Print data
    
    //Delete pointer to structure
    cleanUp(point);
    //Exit stage right!
    return 0;
}
Account *flStruc(){
    Account *point=new Account;//Create pointer to structure
    point->totChck=0;//initialize to 0
    point->totDeps=0;//initialize to 0
    cout<<"Enter your name"<<endl;
    getline(cin,point->name);//input name on account
    cout<<"Enter your street address"<<endl;
    getline(cin, point->address);//input address 
    cout<<"Enter your 5 digit account number"<<endl;
    cin>>point->acctNum;//Input account number
    if(point->acctNum<10000||point->acctNum>99999){//Make sure 5 digits
        cout<<"Invalid account number, Exiting program"<<endl;
        exit(EXIT_FAILURE);
    }
    cout<<"Enter your balance at the beginning of the month"<<endl;
    cin>>point->begBal;//input balance at start of month
    point->endBal=point->begBal;
    cout<<"Enter the amount of each check written this month, when done enter 0"
            <<endl;
    float check=0;//Current check being processed
    do{
        cin>>check;
        point->totChck+=check;//add current check onto total check
    }while(check!=0);//loop until user is finished
    cout<<"Enter the amount of each deposit this month, when done enter 0"
            <<endl;
    float deposit=0;//current deposit being processed
    do{
        cin>>deposit;//input current deposit
        point->totDeps+=deposit;//add current deposit onto total
    }while(deposit!=0);//loop until user is done
    return point;//return pointer to structure
}
float calcBal(Account *point){
    int ovrDraw=20;//overdraw fee of $20
    float curBal=point->begBal;//current balance
    curBal-=point->totChck;//subtract checks
    curBal+=point->totDeps;//add deposits
    cout<<endl;
    if(curBal<0){//if account is negative add of fee
        cout<<"Your account has been overdrawn, you have been charged a $20"<< 
                " fee"<<endl;
        curBal-=ovrDraw;//subtract fee from total
    }
    cout<<endl;
    return curBal;//return balance after calculations
}
void ptStruc(Account *point){
    int width=28;//width for formatting output
    cout<<"Account info for "<<point->name<<endl;
    cout<<left<<setw(width)<<"Name :"<<point->name<<endl;
    cout<<left<<setw(width)<<"Address :"<<point->address<<endl;
    cout<<left<<setw(width)<<"Account number:"<<point->acctNum<<endl;
    cout<<left<<setw(width)<<"Balance at start of month "<<"$"<<point->begBal
            <<endl;
    cout<<left<<setw(width)<<"Total written in checks :"<<"$"<<point->totChck
            <<endl;
    cout<<left<<setw(width)<<"Total deposited :"<<"$"<<point->totDeps<<endl;
    cout<<left<<setw(width)<<"Your current balance is :"<<"$"<<point->endBal
            <<endl;
}
void cleanUp(Account *point){
    delete point;
}